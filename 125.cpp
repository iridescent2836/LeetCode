#include "header.h"
 
// the api is good. in fact, you can implement your own isalnum() and tolower()
// if you don't remember the api. 
class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size() - 1;
        int left = 0;

        while(left < right){
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            if(left < right){
                if(tolower(s[left++]) != tolower(s[right--])) {
                    return false;
                }
            }

        }
        return true;
    }
};