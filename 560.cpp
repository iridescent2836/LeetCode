#include "header.h"


// naive method.
// time: O(n^2)
// space: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int sum = 0;
            for(int j = i;j < len; j++){
                sum+=nums[j];
                if(sum==k) ret++;
            }
        }
        return ret;
    }
};


/**
 * hash + prefix sum
 * prefix[j] = nums[0]+...+nums[j]
 * we set prefix[0] = 0;
 * nums[i] + ... + nums[j] = prefix[j]-prefix[i-1]: i>=1
 * To check if there exists any subarray that ends at index j and has a sum equal to k, 
 * we just need to check whether there exists an index i such that:
 * prefix[j] = prefix[i-1] + k. or prefix[i-1] =  prefix[j] - k
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int len = nums.size();
        int pre = 0;
        unordered_map<int, int> mp;
        // Before traversing the array, 
        // the prefix sum of 0 is considered to have occurred once 
        // — that represents the sum of the empty subarray.
        mp[0] = 1;

        for(int i = 0; i < len; i++){
            pre+=nums[i];
            if(mp.find(pre-k)!=mp.end()){
                ret+=mp[pre-k];
            }
            mp[pre]+=1;

        }
        return ret;
    }
};