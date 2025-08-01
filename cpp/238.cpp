#include "header.h"

// O(n) time complexity, O(n)space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len, 0);
        vector<int> suffix(len, 0);
        int temp = 1;
        for(int i = 0; i < len; i++){
            temp *= nums[i];
            prefix[i] = temp;
        }
        temp = 1;
        for(int i = len-1; i >= 0; i--){
            temp*=nums[i];
            suffix[i] = temp;
        }

        vector<int> ans(len, 0);
        ans[0] = suffix[1];
        for(int i = 1; i < len-1; i++){
            ans[i] = prefix[i-1]*suffix[i+1];
        }
        ans[len-1] = prefix[len-2];
        return ans;
    }
};

// O(n) time complexity.
// O(1)space complexity: as ans doesn't count into the space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int temp = 1;
        // ans[i] = nums[0]*...*nums[i-1], ans[0] = 1
        for(int i = 1; i < len; i++){
            temp *= nums[i-1];
            ans[i] = temp;
        }
        temp = 1;
        for(int i = len-2; i >=0; i--){
            temp *= nums[i+1];
            ans[i] *= temp;
        }

        return ans;
    }
};