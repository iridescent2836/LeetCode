#include "header.h"

using namespace std;

int maxArea(vector<int>& height) {
    size_t limit = height.size();
    size_t max {0};
    for(size_t i {0};i < limit;++i)
    {
        for(size_t j{i+1};j < limit;++j)
        {
            auto smaller {height[i] < height[j] ? height[i] : height[j]};
            auto distance {j-i};
            auto amount {distance*smaller};
            if(amount > max)
            {
                //is there any way to combine these lines?
                max = amount;
            }
        }
    }
    return max;
}
