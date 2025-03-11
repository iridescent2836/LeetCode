#include "header.h"

// brute way, too much time
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int len = nums.size();
        long long ans = 0;
        for(int l = 0; l < len; l++){
            for(int r = l; r < len; r++){
                int temp = 0;
                for(int i = l; i <=r; i++){
                    temp = temp ^ nums[i];
                }
                if(temp == 0) ans++;
            }
        }
        return ans;
    }
};

// dp too much space
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int len = nums.size();
        long long ans = 0;
        vector<vector<int>> dp (len, vector<int>(len, 0));
        for(int i = 0; i < len; i++){
            dp[i][i] = nums[i];
            if(nums[i] == 0) ans++;
        }

        // dp[i][j] = nums[i] ^ ... ^ nums[j]
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                dp[i][j] = dp[i][j-1] ^ nums[j];
                if(dp[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};

// dp: better space, still too much time
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int len = nums.size();
        long long ans = 0;
        vector<int> dp(len, 0);
        for(int l = 0; l < len; l++){
            if(nums[l] == 0) ans++;
            int temp = nums[l];
            for(int r = l+1; r < len; r++){
                temp = temp ^ nums[r];
                if(temp == 0) ans++;
            }
        }
        return ans;
    }
};



// too clever, 详见官方题解

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int mask = 0; 
        long long ans = 0;
        cnt[0] = 1;
        for(int x: nums){
            mask ^= x;
            ans += cnt[mask];
            cnt[mask]++;
        }
        return ans;
    }
};