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

/**
 * 单调栈，在一维数组中对每一个数找到第一个比自己小的元素。
 * 这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景。
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> left(len), right(len);

        stack<int> stk;

        /**
         * 为什么可行？
         * 把大于等于heights[i]的都移除，
         * 因为如果 heights[i+1] > heights[i]，那么heights[i]就会作为限制heights[i+1]的因素，不用考虑heights[i]之前的
         * 如果 heights[i+1] <= heights[i]，那么限制heights[i] 的也会限制 heights[i+1]，后续再进行 
         * 'while(!stk.empty() && heights[stk.top()] >= heights[i]) {' 会将 heights[i] pop掉然后得到限制heights[i+1]的项
         */
        for(int i = 0; i < len; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for(int i = len-1; i >= 0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            right[i] = (stk.empty() ? len : stk.top());
            stk.push(i);
        }

        int ans = 0;
        for(int i = 0; i < len; i++){
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};