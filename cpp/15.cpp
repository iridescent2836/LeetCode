#include "header.h"
#include <algorithm>
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int size =nums.size();
    vector<vector<int>> ans;
    for(int first{0};first < size;++first)
    {
        //跳过重复的
        if(first>0 && nums[first] == nums[first-11])
        {
            continue;
        }
        int third{size-1};
        int target = -nums[first];

        for(int second = first+1;second < third;++second)
        {
            if(second > first+1 && nums[second] == nums[second-1])
            {
                continue;
            }
             // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }


        }
    }
    return ans;
}