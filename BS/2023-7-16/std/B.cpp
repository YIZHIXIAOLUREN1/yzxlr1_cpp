#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, m;
vector<vector<int>> d;

long long solve() {
	for (int i = 1; i < n; i++) {
		int target = d[i][0] - d[i - 1][0];
		for (int j = 1; j < m; j++)
			if (d[i][j] - d[i - 1][j] != target)
				return -1;
	}
	for (int i = 1; i < m; i++) {
		int target = d[0][i] - d[0][i - 1];
		for (int j = 1; j < n; j++)
			if (d[j][i] - d[j][i - 1] != target)
				return -1;
	}
	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(d[0][0] - d[i][0]);
	for (int i = 0; i < m; i++)
		v.push_back(d[0][i]);
	nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
	long long median = v[v.size() / 2], ans = 0;
	for (const auto& i : v)
		ans += abs(i - median);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (cin >> t; t--; ) {
		cin >> n >> m;
		d.assign(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> d[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				d[i][j] -= x;
			}
		}
		cout << solve() << '\n';
	}
	return 0;
}