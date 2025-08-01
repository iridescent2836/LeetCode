#include "header.h"

// boring, so boring.
// scan from  top left to bottom right
class Solution {
public:
    bool helper(int rowBegin, int colBegin, int len,const vector<vector<char>>& matrix){
        for(int i = rowBegin; i < rowBegin + len; i++){
            for(int j = colBegin; j < colBegin + len; j++){
                if(matrix[i][j] == '0') return false;
            }
        }
        return true;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxLen = 0; // the current maxlen
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            if(i + maxLen >= row) break;
            for(int j = 0; j < col; j++){
                // checking if maxLen + 1 satisfied
                // len(vector[i,...,i+maxLen]) = maxLen + 1
                if(j + maxLen >= col) break;
                while(j + maxLen < col && i + maxLen < row && helper(i,j,maxLen+1,matrix)) {
                    maxLen++;
                }
            }
        }
        return maxLen*maxLen;
    }
};


/**
 * dp
 * dp[i][j] stores the max side length of square whose Lower right corner is matrix[i][j]
 * 
 * if(matrix[i][j] == '0') dp[i][j] = 0
 * if(matrix[i][j] == '1') dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
 * 
 * https://leetcode.cn/problems/count-square-submatrices-with-all-ones/solutions/101706/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-2/
 * the above link is the detailed proof of the transfer function. 
 * 
 * 简单说一下自己的理解，f(i,j)表示以(i,j)为右下角的正方形的最大边长，
 * 如果 (i,j)为“0”，以(i,j)为右下角不可能构成全为“1”的正方形 => f(i,j)=0，
 * 
 * 如果(i,j)为“1”，至少可以获得边长为1的正方形，还能不能变大只能向左向上扩展边长，
 * 这个时候需要看正上，左边和左上三个点，因为扩展定会将这三个相邻点包含进来，如果三个点中最小值为0，
 * 那么扩展后肯定不行，如果最小值为1，那么三个点都为1，定能扩展成边长为2的正方形，
 * => 同理能扩展到最大的是 min(左，上，左上) + 1。
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        int maxLen = 0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    }
                    maxLen = max(dp[i][j],maxLen);
                }
            }
        }
        return maxLen * maxLen;
    }
};