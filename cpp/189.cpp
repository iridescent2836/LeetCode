#include "header.h"
#include <numeric>

// O(n) space complexity, O(n) time complexity
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copyOfNums = nums;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            nums[(i+k)%len] = copyOfNums[i];
        }
    }
};

// O(1) space complexity, O(n) time complexity
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int count = gcd(len, k);
        for(int start = 0; start < count; start++){
            int prev = nums[start];
            int current = start;
            do{
                int next = (current + k) % len;
                swap(nums[next], prev);
                current = next;
            }while(current != start);
        }
    }
};

// smart method, O(1) space complexity, O(n) time complexity
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start++], nums[end--]);            
        }
    }

    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums,0,len-1);
        reverse(nums,0,k);
        reverse(nums, k+1,len-1);
    }
};