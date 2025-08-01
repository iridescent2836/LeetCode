#include "header.h"

using namespace std;

// what the hell are you writing? can't you just use `size_t max = 0` ?
//             --- 2025-7-2
int maxArea(vector<int>& height) {
    size_t right{height.size()-1};
    size_t max{0};
    size_t left{0};

    //use left and right as the bundary of the bottle
    while(left < right)
    {
        //always move the smaller side
        if(height[left] < height[right])
        {
            int temp_area = height[left] * (right-left);
            if(temp_area > max) max = temp_area;
            left++;
        }
        else /*if(height[left] >= height[right])*/
        {
            int temp_area = height[right] * (right-left);
            if(temp_area > max) max = temp_area;
            right--;
        }
    }
    return max;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;

        while(left < right){
            int temp = 0;
            if(height[left] < height[right]){
                temp = height[left];
                left++;
            } else {
                temp = height[right];
                right--;
            }
            temp *= (right-left+1);
            maxWater = max(maxWater, temp);
        }
        return maxWater;
    }
};
