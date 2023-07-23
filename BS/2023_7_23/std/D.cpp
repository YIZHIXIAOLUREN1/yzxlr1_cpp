#include <bits/stdc++.h>
using namespace std;
int main() {
long long n;
int m, k;
cin >> n >> m >> k;
const int mk = m * k;
const int P = 998244353;
vector<int> p(mk + 1), vp(mk + 1);
p[0] = 1;
for (int i = 1; i <= mk; i++) p[i] = 1ll * p[i-1] * i % P;
auto inv = [&](int a) {
int b = P - 2, c = 1;
while (b) {
if (b & 1) c = 1ll * c * a % P;
a = 1ll * a * a % P, b >>= 1;
}
return c;
};
vp[mk] = inv(p[mk]);
for (int i = m * k; i; i--) vp[i-1] = 1ll * vp[i] * i % P;
auto binom = [&](int a, int b) {
return a >= b ? 1ll * p[a] * vp[b] % P * vp[a-b] % P : 0;
};
int ans = 0;
for (int A = n % m; A <= n; A += m) {
if (A < k) continue;
if (A > k * (m - 1)) break;
long long c = (n - A) / m;
int now = 0;
for (int i = 0; i <= k; i++)
if (i & 1) now = ((now - 1ll * binom(k, i) * binom(A - i * (m - 1) - 1,
k - 1)) % P + P) % P;
else now = (now + 1ll * binom(k, i) * binom(A - i * (m - 1) - 1, k - 1))
% P;
for (int i = 1; i < k; i++)
now = (c + i) % P * now % P;
now = 1ll * now * vp[k-1] % P;
ans = (ans + now) % P;
}
cout << ans << endl;
return 0;
}