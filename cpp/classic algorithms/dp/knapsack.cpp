#include <iostream>
#include <vector>
using namespace std;

// 01 背包：每件物品只能用一次
int knapsack01(int C, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<int> dp(C + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = C; j >= w[i]; j--) { // 从大到小
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[C];
}

// 完全背包：每件物品可以无限次使用
/**
 * dp[j] 是 
 */
int knapsackComplete(int C, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<int> dp(C + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= C; j++) { // 从小到大
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[C];
}

/**
 * dp[i][j] 容量为[j]的背包，选前i个物品能获得的最大价值
 */

// 01 背包：每件物品只能选一次
int knapsack01_dim_2(int C, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = dp[i-1][j]; // 不选第 i 件
            if (j >= w[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i-1]] + v[i-1]);
            }
        }
    }
    return dp[n][C];
}

// 完全背包：每件物品可无限选
int knapsackComplete_dim_2(int C, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = dp[i-1][j]; // 不选第 i 件
            if (j >= w[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i][j - w[i-1]] + v[i-1]); 
                // 注意这里是 dp[i][...] 而不是 dp[i-1][...]，因为可以重复选
            }
        }
    }
    return dp[n][C];
}

int main() {
    int C = 10;
    vector<int> w = {2, 3, 5};
    vector<int> v = {4, 5, 10};

    cout << "01背包: " << knapsack01(C, w, v) << endl;
    cout << "完全背包: " << knapsackComplete(C, w, v) << endl;
}
