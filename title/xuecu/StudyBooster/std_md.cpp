#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define MAXM 200005
using namespace std;
 
int n, m;
int a[MAXN];
 
int pos[MAXN];
struct Query {
    int idx, l, r;
}q[MAXM];
ll ans[MAXM];
 
bool cmp(Query a, Query b) {
    if (pos[a.l] == pos[b.l]) {
        return a.r < b.r;
    }
    return pos[a.l] < pos[b.l];
}
 
int main(void) {
    cin >> n >> m;
    int siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = i / siz;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }
    sort(q, q + m, cmp);
 
    int l = 1, r = 0;
    ll res = 0;
    for (int i = 0; i < m; i++) {
        while (q[i].l < l) res += a[--l];
        while (q[i].r > r) res += a[++r];
        while (q[i].l > l) res -= a[l++];
        while (q[i].r < r) res -= a[r--];
        ans[q[i].idx] = res;
    }
 
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}