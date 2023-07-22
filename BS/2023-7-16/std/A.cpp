#include <iostream>
#include <vector>

using namespace std;

using P = pair<int, int>;

int t;
int n, m, k;
vector<P> g[200005];
bool vis[200005];
int ans[200005];

void dfs(int cur, int val, bool flag) {
	vis[cur] = flag;
	ans[cur] = val;
	for (const auto& [v, w] : g[cur])
		if (vis[v] ^ flag)
			dfs(v, val ^ w, flag);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (cin >> t; t--; ) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			vis[i] = false;
		}
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
		int last;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(last = i, 0, true);
		dfs(last, k - 1, false);
		bool ok = true;
		for (int i = 1; i <= n; i++)
			for (const auto& [v, w] : g[i])
				ok &= w == (ans[i] ^ ans[v]);
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << "\n "[i + 1 <= n];
	}
	return 0;
}