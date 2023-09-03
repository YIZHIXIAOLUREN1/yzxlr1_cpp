#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
int n;
cin >> n;
vector<vi> e(n + 1);
for (int i = 1; i < n; i++) {
int x, y;
cin >> x >> y;
e[x].push_back(y), e[y].push_back(x);
}
vi a(n + 1);
ll sum = 0;
for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
vi f(n + 1), s(n + 1);
vector<ll> S(n + 1), c(n + 1);
function<void(int)> dfs = [&](int x) {
s[x] = 1, S[x] = a[x], c[x] = a[x];
priority_queue<pair<double, int>> q;
for (auto y : e[x]) {
if (y == f[x]) continue;
f[y] = x;
dfs(y);
s[x] += s[y], S[x] += S[y], c[x] += c[y];
q.push(make_pair(1.0 * S[y] / s[y], y));
}
int t = 1;
while (q.size()) {
int y = q.top().second;
q.pop();
c[x] += t * S[y], t += s[y];
}
};
dfs(1);
ll ans = c[1];
vector<ll> d(n + 1);
dfs = [&](int x) {
vector<pair<double, int>> q;
if (x != 1) q.push_back(make_pair(1.0 * (sum - S[x]) / (n - s[x]), f[x]));
ll k = a[x] + d[x];
for (auto y : e[x]) {
if (y == f[x]) continue;
k += c[y];
q.push_back(make_pair(1.0 * S[y] / s[y], y));
}
sort(q.begin(), q.end());
reverse(q.begin(), q.end());
int t = 1;
for (auto o : q) {
int y = o.second;
k += t * (y == f[x] ? sum - S[x] : S[y]);
t += y == f[x] ? n - s[x] : s[y];
}
if (x != 1) ans = min(ans, k);
reverse(q.begin(), q.end());
ll w = 0;
for (auto o : q) {
int y = o.second;
t -= y == f[x] ? n - s[x] : s[y];
if (y != f[x]) d[y] = k - c[y] - w * s[y] - S[y] * t;
w += y == f[x] ? sum - S[x] : S[y];
}
for (auto y : e[x]) {
if (y == f[x]) continue;
dfs(y);
}
};
dfs(1);
cout << ans << endl;
return 0;
}
