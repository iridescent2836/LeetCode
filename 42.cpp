#include "header.h"


/**
 * Method---traverse each column-dp:
 * 
 * the water that canbe filled in column `i` is
 * max( min(max_left(i), max_right(i)) - height[i], 0);
 * max_left[i] = max(nums[0,..., i-1])
 * max_right[i] = max(nums[i+1,...,n])
 * 
 * we use dp to calculate max_left and max_right
 * max_left[i] = max(max_left[i-1], height[i-1]);
 * max_right[i] = max(max_right[i+1], height[i+1]);
 * 
 * time complexity: O(n)
 * space complexity: O(n)
 */
class Solution1 {
public:    
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> maxLeft(len, 0);
        for(int i = 1; i < len; i++){
            maxLeft[i] =  max(maxLeft[i-1], height[i-1]);
        }

        vector<int> maxRight(len, 0);
        for(int i = len-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += max(min(maxLeft[i], maxRight[i])-height[i],0);
        }
        return sum;
    }
};

/**
 * method---traverse each column-2 pointers:
 * in fact, maxLeft[i] = max(nums[0,...,i-1]), maxRight[i] = max(nums[i+i,...,n]),
 * we can use 2 pointers instead of dp to calculate the max using less space
 * 
 * leftMax = max(nums[0,...,left-1])
 * rightMax = max(nums[right+1,...,n])
 * 
 * if(leftMax < rightMax), the nums[left] is determined, and 
 * the water can be added at nums[left] =  max(leftMax-height[left], 0)
 * 
 * and vice versa
 * 
 * time complexity: O(n)
 * space complexity: O(1)
 */
class Solution2 {
public:    
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = height.size()-1;

        int sum = 0;
        while(left <= right){
            if(leftMax < rightMax){
                sum += max(leftMax-height[left], 0); // avoid adding negative numbers
                leftMax = leftMax < height[left] ? height[left] : leftMax; // update leftMax
                left++;
            } else {
                sum += max(rightMax-height[right], 0); 
                rightMax = rightMax < height[right] ? height[right] : rightMax;
                right--;
            }
        }
        return sum;
    }
};



/**
 * Mehod---stack:
 * 当后面的柱子高度比前面的低时，是无法接雨水的，当找到一根比前面高的柱子，就可以计算接到的雨水
 * 所以使用单调递减栈
 * 
 * clever method. i didn't fully understand. 
 */
class Solution3 {
public:    
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int len = height.size();
        for(int i = 0; i < len; i++){
            // encounter a higher pole-height[i], can add water
            while(!stk.empty() && height[i] > height[stk.top()]){
                int top = stk.top(); // the place that could hold water
                stk.pop();
                if(stk.empty()) break; // no pole that is before the pole to hold water, no water can be added, break;
                int left = stk.top(); 
                int currWidth = i - left - 1;
                cout << currWidth << endl;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main() {
    Solution3 s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(height);
    return 0;

}