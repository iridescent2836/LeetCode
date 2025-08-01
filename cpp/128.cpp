#include "header.h"

// stupid and incorrect way
// because there are duplicate 
// elements in `nums`
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        sort(nums.begin(), nums.end());
        int ret = 1;
        int count = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] == nums[i-1]){ // clever, skip the duplicate element
                continue;
            } else if(nums[i] == nums[i-1]+1){
                count++;
            } else{
                ret = max(ret, count);
                count = 1;
            }
            if (i == len - 1) ret = max(ret, count); // clever, deal with the boundary seperately
        }
        return ret;
    }
};

// stupid and functional
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        else{
            sort(nums.begin(), nums.end());
            int cnt = 1, ans = 1;
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] == nums[i - 1] + 1) cnt++;
                else if (nums[i] == nums[i - 1]);
                else {
                    ans = max(ans, cnt);
                    cnt = 1;
                }
                if (i == nums.size() - 1) ans = max(ans, cnt);
            }
            return ans;
        }
    }
};

// cleverer than me
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len <=  1) return len;
        unordered_set<int> num_set;
        for(const int& num: nums){
            num_set.insert(num);
        }

        int ret = 0;

        for(const int& num: num_set){
            // to avoid searching form `x+1` when `x, x+1, x+2, ..., x+y` exists.
            if(!num_set.count(num-1)){
                int currentNum = num;
                int currentStrike = 1;

                while(num_set.count(currentNum+1)){
                    currentNum += 1;
                    currentStrike += 1;
                }
                ret = max(ret, currentStrike);
            }
        }
        return ret;
    }
};