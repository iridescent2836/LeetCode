#include "header.h"

int jump(vector<int>& nums) {
    int boundary = 0;
    int maxStep = 0;
    int step = 0;
    int startJumpPos = 0;
    int len = nums.size();
    while(boundary < len - 1) {
         
        for(int i = startJumpPos; i <= boundary; i++) {
            // can reach a further boundary
            // update boundary and start jump pos
            if(maxStep < i + nums[i]) {
                maxStep = i + nums[i];
                startJumpPos = i;
            } 
        }
        boundary = maxStep;
        step++;
    }

    return step;
}


int main() {
    vector<int> nums = {0};
    int ans = jump(nums);

    cout << ans << endl;

    return 0;
}