#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int last1 = a[n - 1];
        int last2 = a[n - 2];
        vector<int> res;
        
        for (int i = 0; i < k; i++) {
            int x;
            // 从1,2,3中选择一个与最后两个元素不同的数字
            for (int candidate = 1; candidate <= 3; candidate++) {
                if (candidate != last1 && candidate != last2) {
                    x = candidate;
                    break;
                }
            }
            res.push_back(x);
            // 更新最后两个元素
            last2 = last1;
            last1 = x;
        }
        
        // 输出结果
        for (int i = 0; i < k; i++) {
            cout << res[i];
            if (i < k - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}