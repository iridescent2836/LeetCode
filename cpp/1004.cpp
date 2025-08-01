#include "header.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        int ret = 0;
        // the window is nums[left, right)
        while(right < len) {
            // 窗口向右扩张
            if(nums[right] == 1){
                right++;
            }
            // 窗口继续向右扩张
            else if(k > 0) {
                k--;
                right++;
            }
            // 最左边窗口回退
            else {
                int sublen = right - left;
                cout << left << ' ' << right << '\n';
                ret = sublen > ret ? sublen : ret;
                while(nums[left] == 1) left++;
                if(nums[left] == 0) k++;
                left++;
            }
        }

        // for the situation of [0, 0, 0, 1], k = 3
        int sublen = right - left;
        cout << left << ' ' << right << '\n';
        ret = sublen > ret ? sublen : ret;

        return ret;

    }
};

/**
 * 和我的算法思路相似，但是可读性差非常多，虽然正确。
 * 最好不要学这种写法。
 */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;

        while(right < nums.size()) {
            if(nums[right++] == 0) k--;
            if(k < 0 && nums[left++] == 0) k++;
        }
        return right - left;

    }
};


int main() {
    vector<int> test = {1,1,1,0,0,0,1,1,1,1,0};
    Solution s;
    s.longestOnes(test, 2);
}