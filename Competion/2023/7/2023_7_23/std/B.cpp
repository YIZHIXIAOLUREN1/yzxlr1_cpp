#include <bits/stdc++.h>
#define dbg(x) cerr << #x" = " << (x) << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
int n, P;
cin >> n >> P;
vi a(n + 1);
for (int i = 1; i <= n; i++) cin >> a[i];
vector<vi> c(n + 1, vi(n + 1)), g(n + 1, vi(n + 1));
c[0][0] = 1;
for (int i = 1; i <= n; i++) {
c[i][0] = c[i][i] = 1;
for (int j = 1; j < i; j++)
c[i][j] = (c[i-1][j-1] + c[i-1][j]) % P;
}
for (int j = 1; j <= n; j++) {
g[0][j] = 1;
for (int i = j; i <= n; i += j)
g[i][j] = 1ll * g[i-j][j] * c[i-1][j-1] % P;
}
vector<vi> f(n + 2, vi(n + 1));
f[n+1][0] = 1;
for (int i = n; i; i--)
for (int j = 0; j <= n; j++)
if (f[i+1][j])
for (int k = 0; k * i <= j + a[i]; k++)
f[i][j+a[i]-k*i] = (f[i][j+a[i]-k*i] + 1ll * c[j+a[i]][k*i] *
g[k*i][i] % P * f[i+1][j]) % P;
cout << f[1][0] << endl;
return 0;
}
