#include "header.h"

// my version

/*
类似 1049
dp_zeros[i][j][k] 表示用前 i 个子串是否能凑出一个组合 最多有 j 个 one 和 k 个 zero 的最大子串个数

*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> zero_cnt(strs.size(), 0);
        vector<int> one_cnt(strs.size(), 0);

        for (int i = 0; i < strs.size(); ++i) {
            for (char ch: strs[i]) {
                ch == '1' ? ++one_cnt[i] : ++zero_cnt[i];
            }
        }


        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(n+1, vector<int>(m+1, 0)));
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= m; ++ k) {
                    if (j < one_cnt[i] || k < zero_cnt[i]) dp[i+1][j][k] = dp[i][j][k];
                    else dp[i+1][j][k] =std::max(dp[i][j][k], dp[i][j - one_cnt[i]][k - zero_cnt[i]] + 1);
                }

            }
        }

        return dp[strs.size()][n][m];
    }
};

// optimized by gpt
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (auto &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) zeros += (c == '0');
            ones = s.size() - zeros;
            
            // 关键：要从后往前更新，避免重复使用同一个字符串
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
