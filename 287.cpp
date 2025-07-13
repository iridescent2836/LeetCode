#include "header.h"

/**
 * 暴力解法，看是否有个元素是重复的。
 * time: O(n^2)
 * space: O(1)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int curr = nums[i];
            for(int j = 0; j < len; j++){
                if(j != i && curr == nums[j]) return curr;
            }
        }
        return -1;
    }
};


/**
 * hash
 * time: O(n)
 * space: O(n)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < len; i++){
            if(mp.find(nums[i]) != mp.end()) return nums[i];
            mp[nums[i]] = 1;
        }
        return -1;
    }
};

/**
 * floyd circle algorithm. 
 * 
 * A. 一定存在环吗？
 * 是的。因为index 范围是[0,n] value范围是[1,n], 把value作为index一定可以不断的指向
 * 下一个位置，而数组容量有限，所以一定存在环。
 * 
 * 结论 1： 不管从什么位置开始，都会产生环。
 * 
 * B. 环一定是因为重复数字产生吗？
 * 不一定。举例：
 * 
 * value 6 2 1 5 5 3 4
 * 
 * index 0 1 2 3 4 5 6
 * 
 * 这里从index 0开始，形成了
 * 
 * 6->4->5(i:4)->3(环起点)->5(i:3)-
 *                ↑-------------
 * 这是因为重复数字指向了同一个位置，从而产生了环；
 * 
 * 但是如果从index 1开始，也形成了2-1-2这样一个环。这里没有重复数字也产生了环，
 * 可以把它叫做独立环。
 * 
 * 结论 2：由于开始的位置不同，存在这两种不同类型的环：独立环和重复值环。
 * 
 * C. 从index 0开始，产生的环里一定包含重复数字吗？
 * 是的。因为value的值域[1,n]不包括0，所以index 0不能被其他值指向，
 * 所以index 0一定不会在某个环内，而是环外的一个节点。
 * 结合结论 1和结论 2，得知index 0如果要走到一个环中，
 * 一定是因为重复数字的value都指向了独立环的一个节点(环起点)，
 * 其中一个重复节点在环内，一个在环外。index 0 在索引若干次以后会指向在环外的那个
 * 重复值节点，于是形成了
 * 
 * index 0 -> ... -> 重复值节点 -> 环起点 -> ...
 * 
 *                                 ↑          |
 * 
 *                             重复值节点 < --
 * 这样的结构。没有重复值，index 0 开始的链是无法加入环的！
 * 
 * 总结：从 index0 开始，一定会形成由重复数字形成的环；从其他位置开始不一定。
 * 因此，如果修改题目为index 范围是[0,n] value范围是[0,n-1], 
 * 则需要从 index n （value 中不存在的值）开始，才能找到重复数字，从其他位置开始，
 * 可能会形成不需要重复数字的独立环。
 * 
 * 两倍速度差保证了乌龟跑完一圈，兔子跑完两圈，所以一定能在乌龟跑完一圈之时或者之前完成兔子对乌龟的套圈。
 * 
 * 对为何两次循环可以找到入口见下面题解：
 * https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // to check if there's a circle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // to find the beginning of the circle. 
        slow = 0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
