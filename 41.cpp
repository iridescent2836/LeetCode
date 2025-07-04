#include "header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max = INT32_MIN;
        for(auto num: nums){
            mp[num]++;
            max = num > max ? num : max;
        }
        int ret = 1;
        int len = nums.size();
        while(ret <= max){
            if(mp.find(ret) == mp.end()) break;
            ret++;
        }
        return ret;

    }
};

/**
 * 对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1,N+1] 中。
 * 这是因为如果 [1,N] 都出现了，那么答案是 N+1，否则答案是 [1,N] 中没有出现的最小正整数
 */