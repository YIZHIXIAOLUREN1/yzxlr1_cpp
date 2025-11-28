#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

struct Node {
    long long sum;  // 区间价值和
    int cnt[26];    // 每种字母出现次数
    int first[26];  // 每种字母第一次出现位置（相对位置）
    int last[26];   // 每种字母最后一次出现位置（相对位置）
    
    Node() {
        sum = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
    }
};

int n, q;
string s;
long long a[MAXN];
Node tree[4 * MAXN];

// 合并两个节点
Node merge(const Node& left, const Node& right, int l, int mid, int r) {
    Node res;
    res.sum = left.sum + right.sum;
    
    // 合并计数信息
    for (int i = 0; i < 26; i++) {
        res.cnt[i] = left.cnt[i] + right.cnt[i];
        
        // 合并first
        if (left.first[i] != -1) {
            res.first[i] = left.first[i];
        } else if (right.first[i] != -1) {
            res.first[i] = (mid - l + 1) + right.first[i];
        } else {
            res.first[i] = -1;
        }
        
        // 合并last
        if (right.last[i] != -1) {
            res.last[i] = (mid - l + 1) + right.last[i];
        } else if (left.last[i] != -1) {
            res.last[i] = left.last[i];
        } else {
            res.last[i] = -1;
        }
    }
    
    // 检查配对并计算被消灭的价值
    for (int i = 0; i < 26; i++) {
        if (left.cnt[i] % 2 == 1 && right.cnt[i] % 2 == 1) {
            // 左右区间都有奇数个，会配对消灭
            int left_pos = left.last[i];  // 左区间最后一个该字母
            int right_pos = (mid - l + 1) + right.first[i];  // 右区间第一个该字母
            
            // 消灭从left_pos到right_pos的所有磁铁
            // 这里需要计算这个区间的价值和
            // 由于实现复杂，这里简化处理：在查询时处理配对
        }
    }
    
    return res;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = a[l];
        int c = s[l] - 'a';
        tree[node].cnt[c] = 1;
        tree[node].first[c] = 0;
        tree[node].last[c] = 0;
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], l, mid, r);
}

void update(int node, int l, int r, int idx, long long val) {
    if (l == r) {
        a[l] = val;
        tree[node].sum = val;
        // 重置计数信息
        memset(tree[node].cnt, 0, sizeof(tree[node].cnt));
        memset(tree[node].first, -1, sizeof(tree[node].first));
        memset(tree[node].last, -1, sizeof(tree[node].last));
        
        int c = s[l] - 'a';
        tree[node].cnt[c] = 1;
        tree[node].first[c] = 0;
        tree[node].last[c] = 0;
        return;
    }
    
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(2 * node, l, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, r, idx, val);
    }
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], l, mid, r);
}

// 简化的查询：直接计算区间[l,r]的配对情况
long long query_simple(int l, int r) {
    vector<int> pos[26];
    
    // 收集每种字母在区间内的位置
    for (int i = l; i <= r; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    
    vector<bool> eliminated(r - l + 1, false);
    
    // 处理每种材料的配对
    for (int c = 0; c < 26; c++) {
        const auto& positions = pos[c];
        int m = positions.size();
        
        // 配对：第1&2、第3&4...
        for (int i = 0; i + 1 < m; i += 2) {
            int left_pos = positions[i];
            int right_pos = positions[i + 1];
            
            // 消灭从left_pos到right_pos的所有磁铁
            for (int j = left_pos; j <= right_pos; j++) {
                eliminated[j - l] = true;
            }
        }
    }
    
    // 计算剩余磁铁的价值和
    long long result = 0;
    for (int i = l; i <= r; i++) {
        if (!eliminated[i - l]) {
            result += a[i];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cin >> s;
    s = " " + s;  // 转为1-indexed
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 构建线段树
    build(1, 1, n);
    
    cin >> q;
    
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        
        if (type == 1) {
            update(1, 1, n, x, y);
        } else {
            // 对于查询，使用简化版本
            cout << query_simple(x, y) << "\n";
        }
    }
    
    return 0;
}