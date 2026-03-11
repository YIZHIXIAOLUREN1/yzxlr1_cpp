#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 7;
const int INF = 2147483647;

int n, m;
int arr[N];
mt19937 rnd(std::random_device{}());

// 内层：FHQ Treap 节点
struct node {
    node *ch[2];
    int cnt, siz;
    int val, prio;
    node(int _val) : val(_val), cnt(1), siz(1), prio(rnd()) { ch[0] = ch[1] = nullptr; }
    void upd_siz() { siz = cnt + (!ch[0] ? 0 : ch[0]->siz) + (!ch[1] ? 0 : ch[1]->siz); }
};

pair<node *, node *> split_val(node *cur, int val) {
    if (cur == nullptr) return {nullptr, nullptr};
    if (cur->val <= val) {
        auto temp = split_val(cur->ch[1], val);
        cur->ch[1] = temp.first;
        cur->upd_siz();
        return {cur, temp.second};
    } else {
        auto temp = split_val(cur->ch[0], val);
        cur->ch[0] = temp.second;
        cur->upd_siz();
        return {temp.first, cur};
    }
}

node *merge(node *u, node *v) {
    if (u == nullptr) return v;
    if (v == nullptr) return u;
    if (u->prio < v->prio) {
        u->ch[1] = merge(u->ch[1], v);
        u->upd_siz();
        return u;
    } else {
        v->ch[0] = merge(u, v->ch[0]);
        v->upd_siz();
        return v;
    }
}

// 注意这里改成传引用引用，作用于特定的 root
void insert(node *&rt, int val) {
    auto left = split_val(rt, val);
    auto tg = split_val(left.first, val - 1);
    node *nwno;
    if (tg.second == nullptr) {
        nwno = new node(val);
    } else {
        tg.second->cnt++;
        tg.second->upd_siz();
    }
    node *nl = merge(tg.first, tg.second == nullptr ? nwno : tg.second);
    rt = merge(nl, left.second);
}

void del(node *&rt, int val) {
    auto left = split_val(rt, val);
    auto tg = split_val(left.first, val - 1);
    if(tg.second) {
        if (tg.second->cnt > 1) {
            tg.second->cnt--;
            tg.second->upd_siz();
            tg.first = merge(tg.first, tg.second);
        } else {
            delete tg.second;
            tg.second = nullptr;
        }
    }
    rt = merge(tg.first, left.second);
}

// 在单棵平衡树中查询严格小于 val 的元素个数
int get_less_cnt(node *&rt, int val) {
    auto left = split_val(rt, val - 1);
    int res = (left.first == nullptr ? 0 : left.first->siz);
    rt = merge(left.first, left.second);
    return res;
}

// 在单棵平衡树查询前驱
int qpre(node *&rt, int val) {
    auto temp = split_val(rt, val - 1);
    if(temp.first == nullptr) {
        rt = merge(temp.first, temp.second);
        return -INF;
    }
    node *cur = temp.first;
    while(cur->ch[1]) cur = cur->ch[1];
    int res = cur->val;
    rt = merge(temp.first, temp.second);
    return res;
}

// 在单棵平衡树查询后继
int qnex(node *&rt, int val) {
    auto temp = split_val(rt, val);
    if(temp.second == nullptr) {
        rt = merge(temp.first, temp.second);
        return INF;
    }
    node *cur = temp.second;
    while(cur->ch[0]) cur = cur->ch[0];
    int res = cur->val;
    rt = merge(temp.first, temp.second);
    return res;
}

// 外层：线段树节点
struct SegNode {
    SegNode *ch[2];
    int l, r, mid;
    node *treap_root; // 该区间的 FHQ Treap 根
    SegNode(int _l, int _r) : l(_l), r(_r), treap_root(nullptr) {
        ch[0] = ch[1] = nullptr;
        mid = (_l + _r) / 2;
    }
} *root_seg;

void build(SegNode *cur) {
    for (int i = cur->l; i <= cur->r; i++) {
        insert(cur->treap_root, arr[i]);
    }
    if (cur->l == cur->r) return;
    cur->ch[0] = new SegNode(cur->l, cur->mid);
    cur->ch[1] = new SegNode(cur->mid + 1, cur->r);
    build(cur->ch[0]);
    build(cur->ch[1]);
}

// 1. 查询 k 在区间内的排名
int query_rank(SegNode *cur, int L, int R, int val) {
    if (L <= cur->l && cur->r <= R) {
        return get_less_cnt(cur->treap_root, val);
    }
    if (cur->l > R || cur->r < L) return 0;
    return query_rank(cur->ch[0], L, R, val) + query_rank(cur->ch[1], L, R, val);
}

// 2. 查询区间内排名为 k 的值 (通常需在主函数包装并二分答案，见下文)
int query_val_by_rank(int L, int R, int k) {
    int l = -1e8, r = 1e8, ans = -1; // 根据题目值域调整
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (query_rank(root_seg, L, R, mid) + 1 <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

// 3. 修改某一位置上的数值
void update(SegNode *cur, int pos, int old_val, int new_val) {
    del(cur->treap_root, old_val);
    insert(cur->treap_root, new_val);
    if (cur->l == cur->r) return;
    if (pos <= cur->mid) update(cur->ch[0], pos, old_val, new_val);
    else update(cur->ch[1], pos, old_val, new_val);
}

// 4. 查询 k 在区间内的前驱
int query_pre(SegNode *cur, int L, int R, int val) {
    if (L <= cur->l && cur->r <= R) {
        return qpre(cur->treap_root, val);
    }
    if (cur->l > R || cur->r < L) return -INF;
    return max(query_pre(cur->ch[0], L, R, val), query_pre(cur->ch[1], L, R, val));
}

// 5. 查询 k 在区间内的后继
int query_nex(SegNode *cur, int L, int R, int val) {
    if (L <= cur->l && cur->r <= R) {
        return qnex(cur->treap_root, val);
    }
    if (cur->l > R || cur->r < L) return INF;
    return min(query_nex(cur->ch[0], L, R, val), query_nex(cur->ch[1], L, R, val));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    root_seg = new SegNode(1, n);
    build(root_seg);

    while (m--) {
        int opt, l, r, k, pos;
        cin >> opt;
        if (opt == 1) {
            cin >> l >> r >> k;
            cout << query_rank(root_seg, l, r, k) + 1 << "\n";
        } else if (opt == 2) {
            cin >> l >> r >> k;
            cout << query_val_by_rank(l, r, k) << "\n";
        } else if (opt == 3) {
            cin >> pos >> k;
            update(root_seg, pos, arr[pos], k);
            arr[pos] = k; // 记得更新原数组
        } else if (opt == 4) {
            cin >> l >> r >> k;
            int res = query_pre(root_seg, l, r, k);
            cout << (res == -INF ? -2147483647 : res) << "\n";
        } else if (opt == 5) {
            cin >> l >> r >> k;
            int res = query_nex(root_seg, l, r, k);
            cout << (res == INF ? 2147483647 : res) << "\n";
        }
    }
    return 0;
}