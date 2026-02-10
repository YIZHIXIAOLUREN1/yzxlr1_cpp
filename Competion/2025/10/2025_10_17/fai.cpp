#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> intervals(m);
        for (int i = 0; i < m; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        
        // 寻找公共点
        int common_point = -1;
        for (int pos = 1; pos <= n; pos++) {
            bool found_common = true;
            for (auto& interval : intervals) {
                int l = interval.first;
                int r = interval.second;
                if (!(l <= pos && pos <= r)) {
                    found_common = false;
                    break;
                }
            }
            if (found_common) {
                common_point = pos;
                break;
            }
        }
        
        vector<int> p(n);
        
        if (common_point != -1) {
            // 情况1：存在公共点
            int cur = 1;
            for (int i = 0; i < n; i++) {
                if (i == common_point - 1) {
                    p[i] = 0;
                } else {
                    p[i] = cur;
                    cur++;
                }
            }
        } else {
            // 寻找有效的i和j
            bool found_i_j = false;
            int i_val = -1, j_val = -1;
            
            for (int i_candidate = 1; i_candidate <= n; i_candidate++) {
                int L = 1, R = n;
                for (auto& interval : intervals) {
                    int l = interval.first;
                    int r = interval.second;
                    if (l <= i_candidate && i_candidate <= r) {
                        L = max(L, l);
                        R = min(R, r);
                    }
                }
                
                if (L <= R) {
                    if (L != i_candidate) {
                        i_val = i_candidate;
                        j_val = L;
                        found_i_j = true;
                        break;
                    } else if (R != i_candidate) {
                        i_val = i_candidate;
                        j_val = R;
                        found_i_j = true;
                        break;
                    }
                }
            }
            
            if (found_i_j) {
                // 情况2：找到有效的i和j
                vector<bool> used(n, false);
                p[i_val - 1] = 0;
                p[j_val - 1] = 1;
                used[i_val - 1] = true;
                used[j_val - 1] = true;
                
                int cur = 2;
                for (int i = 0; i < n; i++) {
                    if (!used[i]) {
                        p[i] = cur;
                        cur++;
                    }
                }
            } else {
                // 情况3：默认构造
                p[0] = 0;
                p[n - 1] = 1;
                int cur = 2;
                for (int i = 1; i < n - 1; i++) {
                    p[i] = cur;
                    cur++;
                }
            }
        }
        
        // 输出结果
        for (int i = 0; i < n; i++) {
            cout << p[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}