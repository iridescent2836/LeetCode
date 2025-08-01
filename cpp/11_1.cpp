#include "header.h"

using namespace std;

/**
 * what the hell are you writing? 
 * can you stop using so many `auto`?
 *              --- 2025-3-19
 * 
 * same comment, this code sucks. 
 *              --- 2025-7-2
 */
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
