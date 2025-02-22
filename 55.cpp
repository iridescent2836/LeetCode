#include "header.h"



bool canJump(vector<int>& nums) {
    int len = nums.size();
    int mostFar = 0;

    for(int i = 0; i < len; i++) {
        if(i <= mostFar)
            mostFar = i + nums[i] < mostFar ? mostFar : i + nums[i];
        if(mostFar >= len -1)
            return true;
    }
    return false;
}


int main() {
    vector<int> nums = {3,2,1,0,4};

    bool ans = canJump(nums);
    cout << ans << endl;
    return 0;
}