#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

// 生成单个测试点的数据
void generate_test_case(int test_id, int max_n, int max_q, int max_value) {
    string filename = to_string(test_id) + ".in";
    ofstream fout(filename, ios::binary);
    
    // 使用测试点ID作为随机种子的一部分，确保可重复性
    unsigned seed = chrono::system_clock::now().time_since_epoch().count() + test_id;
    mt19937 gen(seed);
    
    // 生成n和q
    int n = uniform_int_distribution<int>(max_n * 0.8, max_n)(gen);
    int q = uniform_int_distribution<int>(max_q * 0.8, max_q)(gen);
    
    fout << n << " " << q << "\n";
    
    // 生成n个正整数
    fout<<"0 ";
    for (int i = 1; i < n; i++) {
        int a_i = uniform_int_distribution<int>(0, max_value)(gen);
        fout << a_i;
        if (i < n - 1) fout << " ";
    }
    fout << "\n";
    
    // 生成q个查询
    for (int i = 0; i < q-1; i++) {
        int len = uniform_int_distribution<int>(0.8*n, n)(gen);
        int l = uniform_int_distribution<int>(1, n-len+1)(gen);
        fout << l << " " << l+len-1 << "\n";
    }
    fout<<"1 1\n";
    fout.close();
    cout << "生成测试点: " << filename << " (n=" << n << ", q=" << q << ")" << "\n";
}

int main() {
    // 测试点配置：可以针对不同测试点设置不同的数据规模
    ios::sync_with_stdio(0);
    cout.tie(0);
    vector<tuple<int, int, int>> test_configs = {
        // {最大n, 最大q, 最大值}
        {1000, 1000, 1000},        // 测试点1-5: 小数据
        {2000, 2000, 1000000000},     // 测试点6-10: 中等数据
        {200000, 200000, 1000},
        {200000, 200000, 1000000000} // 测试点16-20: 最大数据
    };
    
    //cout << "开始生成20个测试点..." << "\n";
    
    for (int i = 1; i <= 20; i++) {
        int config_index;
        if (i <= 5) config_index = 0;
        else if (i <= 10) config_index = 1;
        else if (i <= 15) config_index = 2;
        else config_index = 3;
        
        auto [max_n, max_q, max_value] = test_configs[config_index];
        generate_test_case(i, max_n, max_q, max_value);
    }
    
    //cout << "所有测试点生成完成！" << "\n";
    
    return 0;
}