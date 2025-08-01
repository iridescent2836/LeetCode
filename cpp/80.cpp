#include "header.h"

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            bool isDup = false;
            int len = nums.size();
            int lenAfterRemove = nums.size();

            if(len <= 2) {
                return len;
            }

            int temp = nums[0];
            // using Finite Automaton
            for(int i = 1; i < len; i++) {
                // encounter the different character
                if(temp != nums[i]) {
                    temp = nums[i];
                    isDup = false;
                } else if(temp == nums[i] && isDup == false) { // encounter 1st same caracter
                    isDup = true;
                } else if(temp == nums[i] && isDup == true) { // more than 2 different caracter
                    lenAfterRemove--;
                    // erase the useless character
                    nums.erase(nums.begin() + i);
                    len--;
                    i--; // so that after i++ at the for loop, the pointer point at the same position
                }
            }
            return lenAfterRemove;
        }
    };