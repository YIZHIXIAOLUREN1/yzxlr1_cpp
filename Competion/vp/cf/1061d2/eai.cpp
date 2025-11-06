#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
const ll INF = 1e9 + 7;
int n, a[N];
int f[N];

// 更高效的数组形式动态开点线段树
const int MAX_NODES = 8000000; // 增加到8e6节点

struct FastNode {
    int l, r, mid;
    int val;
    int ch[2];
};

// 使用全局静态数组，避免动态分配
static FastNode tree1[MAX_NODES], tree2[MAX_NODES];
static int idx1, idx2;

class FastSegmentTree {
private:
    FastNode* tree;
    int& idx;
    
    inline int newNode(int l, int r) {
        if(idx >= MAX_NODES) return 0;
        int new_idx = ++idx;
        tree[new_idx].l = l;
        tree[new_idx].r = r;
        tree[new_idx].mid = (l + r) >> 1;
        tree[new_idx].val = 0;
        tree[new_idx].ch[0] = tree[new_idx].ch[1] = 0;
        return new_idx;
    }
    
public:
    FastSegmentTree(FastNode* t, int& i) : tree(t), idx(i) {}
    
    inline void init(int l, int r) {
        idx = 0;
        newNode(l, r);
    }
    
    inline ll query(int cur, int L, int R) {
        if(R < L || cur == 0) return 0;
        if(tree[cur].val == 0) return 0;
        if(L <= tree[cur].l && tree[cur].r <= R) return tree[cur].val;
        if(tree[cur].l > R || tree[cur].r < L) return 0;
        
        ll res = 0;
        if(tree[cur].ch[0]) res += query(tree[cur].ch[0], L, R);
        if(tree[cur].ch[1]) res += query(tree[cur].ch[1], L, R);
        return res;
    }
    
    inline void update(int cur, int tg, int v) {
        if(tree[cur].l == tree[cur].r) {
            tree[cur].val += v;
            return;
        }
        
        if(tg <= tree[cur].mid) {
            if(!tree[cur].ch[0]) tree[cur].ch[0] = newNode(tree[cur].l, tree[cur].mid);
            update(tree[cur].ch[0], tg, v);
        } else {
            if(!tree[cur].ch[1]) tree[cur].ch[1] = newNode(tree[cur].mid + 1, tree[cur].r);
            update(tree[cur].ch[1], tg, v);
        }
        
        // 快速pushup
        tree[cur].val = (tree[cur].ch[0] ? tree[tree[cur].ch[0]].val : 0) + 
                       (tree[cur].ch[1] ? tree[tree[cur].ch[1]].val : 0);
    }
    
    inline ll query(int L, int R) { return query(1, L, R); }
    inline void update(int tg, int v) { update(1, tg, v); }
};

static FastSegmentTree t1(tree1, idx1), t2(tree2, idx2);

int mia, maa;
static int p2[10], pk[10]; // 使用固定大小数组代替vector
int cnt2, cntk;

// 极致优化的check函数
inline bool check(ll x) {
    cnt2 = cntk = 0;
    
    // 快速初始化线段树
    t1.init(0, INF);
    t2.init(0, INF);
    
    // 手动循环展开 + 寄存器优化
    int i = 1;
    for(; i + 7 <= n; i += 8) {
        f[i] = t1.query(mia, a[i] - x); t1.update(a[i], 1);
        f[i+1] = t1.query(mia, a[i+1] - x); t1.update(a[i+1], 1);
        f[i+2] = t1.query(mia, a[i+2] - x); t1.update(a[i+2], 1);
        f[i+3] = t1.query(mia, a[i+3] - x); t1.update(a[i+3], 1);
        f[i+4] = t1.query(mia, a[i+4] - x); t1.update(a[i+4], 1);
        f[i+5] = t1.query(mia, a[i+5] - x); t1.update(a[i+5], 1);
        f[i+6] = t1.query(mia, a[i+6] - x); t1.update(a[i+6], 1);
        f[i+7] = t1.query(mia, a[i+7] - x); t1.update(a[i+7], 1);
    }
    for(; i <= n; i++) {
        f[i] = t1.query(mia, a[i] - x);
        t1.update(a[i], 1);
    }
    
    // 倒序遍历同样优化
    i = n;
    for(; i - 7 >= 1; i -= 8) {
        f[i] += t2.query(a[i] + x, maa); t2.update(a[i], 1);
        f[i-1] += t2.query(a[i-1] + x, maa); t2.update(a[i-1], 1);
        f[i-2] += t2.query(a[i-2] + x, maa); t2.update(a[i-2], 1);
        f[i-3] += t2.query(a[i-3] + x, maa); t2.update(a[i-3], 1);
        f[i-4] += t2.query(a[i-4] + x, maa); t2.update(a[i-4], 1);
        f[i-5] += t2.query(a[i-5] + x, maa); t2.update(a[i-5], 1);
        f[i-6] += t2.query(a[i-6] + x, maa); t2.update(a[i-6], 1);
        f[i-7] += t2.query(a[i-7] + x, maa); t2.update(a[i-7], 1);
    }
    for(; i >= 1; i--) {
        f[i] += t2.query(a[i] + x, maa);
        t2.update(a[i], 1);
    }
    
    // 统计结果
    for(int i = 1; i <= n; i++) {
        if(f[i] < 2) continue;
        if(f[i] == 2) {
            if(cnt2 < 10) p2[cnt2++] = i;
        } else {
            if(cntk < 10) pk[cntk++] = i;
        }
    }
    
    // 快速条件判断
    if(cntk >= 2) return false;
    if(cnt2 + cntk <= 1) return true;
    
    // 根据情况数量快速处理
    if(cnt2 == 2 && cntk == 0) {
        return a[p2[0]] + x <= a[p2[1]];
    }
    if(cnt2 == 1 && cntk == 1) {
        int idx1 = p2[0], idx2 = pk[0];
        if(idx1 > idx2) swap(idx1, idx2);
        return a[idx1] + x <= a[idx2];
    }
    if(cnt2 >= 2 && cntk == 1) {
        for(int j = 0; j < cnt2; j++) {
            int u = p2[j];
            if(pk[0] < u && a[pk[0]] + x > a[u]) return false;
            if(pk[0] > u && a[u] + x > a[pk[0]]) return false;
        }
        return true;
    }
    if(cnt2 == 3 && cntk == 0) {
        return (a[p2[0]] + x <= a[p2[1]] && a[p2[0]] + x <= a[p2[2]]) || 
               (a[p2[0]] + x <= a[p2[1]] && a[p2[1]] + x <= a[p2[2]]) || 
               (a[p2[0]] + x <= a[p2[2]] && a[p2[1]] + x <= a[p2[2]]);
    }
    
    return false;
}

void Solve() {
    cin >> n;
    mia = INF, maa = 0;
    
    // 快速输入和求最值
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < mia) mia = a[i];
        if(a[i] > maa) maa = a[i];
    }
    
    // 优化二分边界
    ll l = mia - maa, r = maa - mia;
    
    // 特殊优化：如果n很小，直接使用更宽松的二分
    if(n <= 1000) {
        while(l < r) {
            ll mid = (l + r + 1) >> 1;
            if(!check(mid)) 
                l = mid;
            else 
                r = mid - 1;
        }
    } else {
        // 对于大数据，使用更激进的二分策略
        while(r - l > 1) {
            ll mid = (l + r) >> 1;
            if(!check(mid)) 
                l = mid;
            else 
                r = mid;
        }
        // 最后检查r
        if(!check(r)) l = r;
    }
    
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        Solve();
    }
    return 0;
}