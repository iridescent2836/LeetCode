#include "header.h"

/**
 * 如果当前位置是负数，我们希望以它前一个位置结尾的某个段的积也是负数，这样可以负负得正，
 * 并且我们希望这个积尽可能小。
 * 如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积也是正数，并且希望它尽可能地大。
 * 
 * 所以维护
 * f_min[i] = min(f_min[i-1] * nums[i], min(f_max[i-1] * nums[i], nums[i]))
 * f_max[i] = max(f_min[i-1] * nums[i], max(f_max[i-1] * nums[i], nums[i]))
 * 
 * time: O(n)
 * space: O(n), could be optimized, but it's not worthy of my time, cause it's too easy. 
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> f_min(len, nums[0]);
        vector<int> f_max(len, nums[0]);

        int max_ = nums[0];
        for(int i = 1; i < len; i++){
            f_min[i] = min(f_min[i-1] * nums[i], min(f_max[i-1] * nums[i], nums[i]));
            f_max[i] = max(f_min[i-1] * nums[i], max(f_max[i-1] * nums[i], nums[i]));
            max_ = max(max_, f_max[i]);
        }
        return max_;
    }
};

/**
 * 结论:一个不包含0的整数序列的连续乘积最大值，一定以起点开始或者以终点结束。
 * 使用反证法证明:
 * 如果连续乘积最大值不以起点开始也不以终点结束，也就是说，结果序列两边都有非0整数。
 * 分类讨论，
 *   如果连续乘积最大值为正，那么结果序列左右两边应该异号，否则可以向两边扩展，
 *       而如果两边异号，那么一定存在一边为正，也可以继续扩展，与假设矛盾。
 *   如果连续乘积最大值为负，那么结果序列两边一定同号，否则可以向两边扩展，
 *       如果同负，那么乘以任意一个负数都会让乘积变大，
 *       如果同正，那么任意一个正数都大于这个负数的连续乘积最大值。
 * 
 * 综上，不以起点开始且不以终点结束的序列，一定不是最大的连续乘积
 * 
 * super super clever. 
 * time: O(2n)
 * space: O(1)
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int product = 1, n = nums.size();
       int max_ = nums[0];

       for(int i = 0;i < n;i++){
           product *= nums[i];
           max_ = max(max_, product);
           // the subarry that include nums[i] should all be zero,
           // so only need to consider subarray whoes beginning idx is larger than i, like nums[i+1,...]
           if(nums[i] == 0){ 
               product = 1;
           }
       }

       product = 1;
       for(int i = n - 1;i >= 0;i--){
           product *= nums[i];
           max_ = max(max_, product);
           if(nums[i] == 0){
               product = 1;
           }
       }

       return max_;
   }
};