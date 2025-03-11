#include "header.h"

class Solution {
public:
    void dfs(vector<vector<int>>& triangle, int i, int j,int& cost){
        if(i==h){
            if(cost<min) min=cost;
            return;
        }
        cost+= triangle[i][j];
        

        dfs(triangle,i+1,j,cost);
        dfs(triangle,i+1,j+1,cost);
        cost -= triangle[i][j];
        return;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        h = triangle.size();
        min = INT32_MAX;
        int cost = 0;
        dfs(triangle,0,0,cost);
        return min;
    }
private:
    int h;
    int min;
};


// dp
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle; // dp may not be the copy of triangle but be the triangle itself
        
        int h = triangle.size();
        int min = INT32_MAX;
        for(int i = 1; i < h; i++){
            int len = triangle[i].size();
            dp[i][0] += dp[i-1][0];
            dp[i][len-1] += dp[i-1][len-2];
            for(int j = 1; j< len-1; j++){
                dp[i][j]+= dp[i-1][j] < dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1];
            }
        }
        int len = triangle[h-1].size();
        for(int i = 0; i < len; i++){
            if(dp[len-1][i] < min) min = dp[len-1][i];
        }
        return min;
    }

};

// dp, optimized space complexity
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int h = triangle.size();
        vector<int>dp(h,0);
        dp[0] = triangle[0][0];
        int min = INT32_MAX;
        for(int i = 1; i < h; i++){
            dp[i] = dp[i-1]+triangle[i][i];
            for(int j = i-1; j >0; j--){
                dp[j] = (dp[j] < dp[j-1] ? dp[j] : dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        for(int i = 0; i < h; i++){
            if(dp[i] < min) min = dp[i];
        }
        return min;
    }
};