#include "header.h"

using namespace std;

int maxArea(vector<int>& height) {
    size_t right{height.size()-1};
    size_t max{0};
    size_t left{0};

    //use left and right as the bundary of the bottle
    for(;right > left;)
    {
        //always move the smaller side
        if(height[left] < height[right])
        {
            int temp_area = height[left] * (right-left);
            if(temp_area > max) max = temp_area;
            left++;
        }
        else /*if(height[left] > height[right])*/
        {
            int temp_area = height[right] * (right-left);
            if(temp_area > max) max = temp_area;
            right--;
        }
    }
    return max;
}
