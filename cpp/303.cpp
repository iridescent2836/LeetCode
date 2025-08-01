#include "header.h"

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n+1);
        sums[0]=0;
        // sums[i+1] = nums[0]+...+nums[i] for i >= 0
        // we set sums[0] = 0
        for(int i = 0; i < n; i++){
            sums[i+1] = nums[i]+sums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */