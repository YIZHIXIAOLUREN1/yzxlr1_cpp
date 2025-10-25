#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int total_length = n * n + 1;
    
    // 查询函数
    auto query = [](const vector<int>& indices) -> vector<int> {
        cout << "? " << indices.size();
        for (int idx : indices) {
            cout << " " << idx;
        }
        cout << endl;
        cout.flush();
        
        int k;
        cin >> k;
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            cin >> result[i];
        }
        return result;
    };
    
    // 第一次查询：整个序列
    vector<int> all_indices(total_length);
    for (int i = 0; i < total_length; i++) {
        all_indices[i] = i + 1;
    }
    
    vector<int> visible = query(all_indices);
    
    // 如果可见索引数量足够，直接返回递增子序列
    if (visible.size() >= n + 1) {
        cout << "! " << visible.size();
        for (int idx : visible) {
            cout << " " << idx;
        }
        cout << endl;
        return 0;
    }
    
    int k = visible.size();
    int last_visible = visible.back();
    
    // 构建最后一个区间 Ik：从 last_visible+1 到 total_length
    vector<int> ik_indices;
    for (int i = last_visible + 1; i <= total_length; i++) {
        ik_indices.push_back(i);
    }
    
    // 如果 Ik 为空（理论上不应该发生），使用备选方案
    if (ik_indices.empty()) {
        // 取第一个可见索引和接下来的n个索引
        vector<int> sequence;
        sequence.push_back(visible[0]);
        for (int i = 1; i <= n; i++) {
            sequence.push_back(visible[0] + i);
        }
        cout << "! " << sequence.size();
        for (int idx : sequence) {
            cout << " " << idx;
        }
        cout << endl;
        return 0;
    }
    
    // 查询 Ik 区间
    vector<int> visible_ik = query(ik_indices);
    
    // 如果 Ik 的可见索引数量足够，返回递增子序列
    if (visible_ik.size() >= n + 1) {
        cout << "! " << visible_ik.size();
        for (int idx : visible_ik) {
            cout << " " << idx;
        }
        cout << endl;
        return 0;
    }
    
    // 构造递减子序列
    // 获取 Ik 中不可见的索引
    vector<int> invisible_ik;
    for (int idx : ik_indices) {
        if (find(visible_ik.begin(), visible_ik.end(), idx) == visible_ik.end()) {
            invisible_ik.push_back(idx);
        }
    }
    
    // 取第一个可见索引和 Ik 中的前 n 个不可见索引
    vector<int> sequence;
    sequence.push_back(visible[0]);
    for (int i = 0; i < n && i < invisible_ik.size(); i++) {
        sequence.push_back(invisible_ik[i]);
    }
    
    cout << "! " << sequence.size();
    for (int idx : sequence) {
        cout << " " << idx;
    }
    cout << endl;
    
    return 0;
}