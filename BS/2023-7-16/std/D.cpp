#include <bits/stdc++.h>
using namespace std;
void read (int &x) {
    char ch = getchar(); x = 0; while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 1e5 + 5;
int n, m, X, a[9][N], mx[256][N], mn[256][N], pw[10], tot, c[N * 8];
struct seg { int l, r; } A[N * 8], B[N * 8];
unordered_map<int, int> mp;
int sa[N], tpa, sb[N], tpb, MX[N], MN[N];
long long res = 0; int now, to[N * 8];
void dela (int l, int r) {
    int val = to[MX[r]];
    if (B[val].l) {
        seg t = B[val]; int L = t.l, R = t.r;
        now -= max (0, min (r, R) - max (l, L) + 1);
    }
    A[MX[r]].l = 0;
}
void adda (int l, int r) {
    int val = to[MX[r]];
    if (B[val].l) {
        seg t = B[val]; int L = t.l, R = t.r;
        now += max (0, min (r, R) - max (l, L) + 1);
    }
    A[MX[r]] = (seg){l, r};
}
void delb (int l, int r) {
    int val = to[MN[r]];
    if (A[val].l) {
        seg t = A[val]; int L = t.l, R = t.r;
        now -= max (0, min (r, R) - max (l, L) + 1);
    }
    B[MN[r]].l = 0;
}
void addb (int l, int r) {
    int val = to[MN[r]];
    if (A[val].l) {
        seg t = A[val]; int L = t.l, R = t.r;
        // if (r == m) printf ("666 %d %d %d %d\n", l, r, L, R);
        now += max (0, min (r, R) - max (l, L) + 1);
    }
    B[MN[r]] = (seg){l, r};
}
signed main() {
    pw[0] = 1; for (int i = 1; i <= 8; ++i) pw[i] = pw[i - 1] * i;
    read (n), read (m), read (X);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j) read (a[i][j]), c[i * m + j] = a[i][j];
    sort (c + 1, c + n * m + 1);
    for (int i = 1; i <= n * m; ++i) {
        if (!mp.count (c[i])) mp[c[i]] = ++tot;
        if (mp.count (c[i] ^ X)) {
            int ta = mp[c[i] ^ X], tb = mp[c[i]];
            to[ta] = tb, to[tb] = ta;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j) a[i][j] = mp[a[i][j]];
    for (int i = 1; i <= m; ++i) mn[0][i] = 1e9;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) if (i >> j & 1) {
             for (int k = 1; k <= m; ++k)
                mx[i][k] = max (mx[i ^ (1 << j)][k], a[j][k]);
             for (int k = 1; k <= m; ++k)
                mn[i][k] = min (mn[i ^ (1 << j)][k], a[j][k]);
            break;
        }
        for (int j = 1; j <= m; ++j) MX[j] = mx[i][j], MN[j] = mn[i][j];
        tpa = tpb = 0; long long ans = 0; now = 0;
        for (int j = 1; j <= m; ++j) {
            while (tpa && MX[sa[tpa]] <= MX[j]) {
                dela (sa[tpa - 1] + 1, sa[tpa]); --tpa;
            }
            while (tpb && MN[sb[tpb]] >= MN[j]) {
                delb (sb[tpb - 1] + 1, sb[tpb]); --tpb;
            }
            sa[++tpa] = j; adda (sa[tpa - 1] + 1, j);
            sb[++tpb] = j; addb (sb[tpb - 1] + 1, j);
            ans += now;
        }
        for (int j = 1; j <= tpa; ++j) A[MX[sa[j]]].l = 0;
        for (int j = 1; j <= tpb; ++j) B[MN[sb[j]]].l = 0;
        int cnt = __builtin_popcount (i);
        res += ans * (n - cnt + 1) * pw[cnt] * pw[n - cnt];
    }
    printf ("%lld\n", res);
    return 0;
}