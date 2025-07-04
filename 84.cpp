#include "header.h"


/**
 * 暴力解法1： 枚举所有的宽
 * 值得记忆，因为枚举宽的形式
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int ret = 0;
        for(int left = 0; left < len; left++){
            // 好办法
            int min_height = heights[left];
            for(int right = left; right < len; right ++) {
                // 好办法
                min_height = min(min_height, heights[right]);
                ret = max(ret, (right - left+1) * min_height);
            }
        }
        return ret;
    }
};

/**
 * 暴力解法2：枚举所有的高
 * 有好技巧
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int ret = 0;
        for(int curr = 0; curr < len; curr++){

            int left, right, height;
            height = heights[curr];
            left = right = curr;
            // 好办法，检查left-1
            while(left >= 1 && heights[left - 1] >= height) left--;
            while(right <= len - 2 && heights[right + 1] >= height) right++;
            ret = max(ret, (right - left + 1) * height);
        }
        return ret;
    }
};