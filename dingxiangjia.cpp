#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double calculateExpectedDrawsTwoSpecificA() {
    // 初始奖品数量
    const int a_total = 3, b_total = 20, c_total = 7;
    
    // 初始概率
    const double p_a = 0.06, p_b = 0.60, p_c = 0.34;
    
    // DP数组：dp[a_remaining][b_remaining][c_remaining][target_a_remaining] 
    // 表示在该状态下抽中所有目标a奖品的期望抽奖次数
    // target_a_remaining: 0-2，表示还需要抽中的目标a奖品数量
    vector<vector<vector<vector<double>>>> dp(
        a_total + 1, 
        vector<vector<vector<double>>>(
            b_total + 1, 
            vector<vector<double>>(
                c_total + 1,
                vector<double>(3, 0.0)
            )
        )
    );
    
    // 遍历所有可能的剩余奖品状态
    for (int a_rem = 0; a_rem <= a_total; ++a_rem) {
        for (int b_rem = 0; b_rem <= b_total; ++b_rem) {
            for (int c_rem = 0; c_rem <= c_total; ++c_rem) {
                for (int target_rem = 0; target_rem <= 2; ++target_rem) {
                    // 如果所有目标a奖品已经抽中，期望为0
                    if (target_rem == 0) {
                        dp[a_rem][b_rem][c_rem][target_rem] = 0.0;
                        continue;
                    }
                    
                    // 如果奖品都抽完了但目标a奖品还没全部抽中，这是不可能的情况，设为0
                    if (a_rem + b_rem + c_rem == 0) {
                        dp[a_rem][b_rem][c_rem][target_rem] = 0.0;
                        continue;
                    }
                    
                    // 如果目标a奖品剩余数量大于实际a奖品剩余数量，期望为0
                    if (target_rem > a_rem) {
                        dp[a_rem][b_rem][c_rem][target_rem] = 0.0;
                        continue;
                    }
                    
                    double current_p_a = p_a, current_p_b = p_b, current_p_c = p_c;
                    
                    // 调整概率：如果某个等级的奖品已经抽完，重新分配概率
                    if (a_rem == 0) {
                        current_p_a = 0;
                    }
                    if (b_rem == 0) {
                        current_p_b = 0;
                    }
                    if (c_rem == 0) {
                        current_p_c = 0;
                    }
                    
                    // 归一化概率
                    double total_p = current_p_a + current_p_b + current_p_c;
                    if (total_p > 0) {
                        current_p_a /= total_p;
                        current_p_b /= total_p;
                        current_p_c /= total_p;
                    } else {
                        dp[a_rem][b_rem][c_rem][target_rem] = 0.0;
                        continue;
                    }
                    
                    double expected = 1.0; // 当前这次抽奖
                    
                    // 计算抽中A等级的情况
                    if (a_rem > 0 && current_p_a > 0) {
                        // 当前a奖品中目标奖品的比例
                        int target_a_in_remaining = min(target_rem, a_rem);
                        int non_target_a_in_remaining = a_rem - target_a_in_remaining;
                        
                        // 抽中目标a奖品的概率
                        if (target_a_in_remaining > 0) {
                            double p_hit_target = (target_a_in_remaining * 1.0 / a_rem) * current_p_a;
                            expected += p_hit_target * dp[a_rem - 1][b_rem][c_rem][target_rem - 1];
                        }
                        
                        // 抽中非目标a奖品的概率
                        if (non_target_a_in_remaining > 0) {
                            double p_hit_non_target = (non_target_a_in_remaining * 1.0 / a_rem) * current_p_a;
                            expected += p_hit_non_target * dp[a_rem - 1][b_rem][c_rem][target_rem];
                        }
                    }
                    
                    // 计算抽中B等级的情况
                    if (b_rem > 0 && current_p_b > 0) {
                        expected += current_p_b * dp[a_rem][b_rem - 1][c_rem][target_rem];
                    }
                    
                    // 计算抽中C等级的情况
                    if (c_rem > 0 && current_p_c > 0) {
                        expected += current_p_c * dp[a_rem][b_rem][c_rem - 1][target_rem];
                    }
                    
                    dp[a_rem][b_rem][c_rem][target_rem] = expected;
                }
            }
        }
    }
    
    // 初始状态：所有奖品都在，需要抽中2个目标a奖品
    return dp[a_total][b_total][c_total][2];
}

int main() {
    double result = calculateExpectedDrawsTwoSpecificA();
    cout << fixed << setprecision(6);
    cout << "抽中两个指定A奖品的期望抽奖次数: " << result << endl;
    return 0;
}