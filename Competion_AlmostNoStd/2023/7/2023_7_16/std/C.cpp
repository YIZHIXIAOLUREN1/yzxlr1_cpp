#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using P = pair<int, int>;

int n;
vector<int> s[5005];
vector<int> t[5005];
int x[300005];
int c[300005];
bool vis[300005];
priority_queue<P> q[5005];
long long dp[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r >> x[i] >> c[i];
		s[l].push_back(i);
		t[r].push_back(i);
	}
	long long ans = 0;
	for (int i = 1; i <= 5000; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		for (const auto& j : s[i])
			q[x[j]].emplace(c[j], j);
		for (int j = 1; j <= 5000; j++) {
			while (!q[j].empty() && vis[q[j].top().second])
				q[j].pop();
			if (q[j].empty())
				continue;
			ans = max(ans, dp[i + j] = max(dp[i + j], dp[i] + q[j].top().first));
		}
		for (const auto& j : t[i])
			vis[j] = true;
	}
	cout << ans << '\n';
	return 0;
}