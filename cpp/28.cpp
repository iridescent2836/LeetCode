#include "header.h"

// brute
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay = haystack.size();
        int lenNeedle = needle.size();

        for(int i = 0; i < lenHay - lenNeedle + 1; i++){
            bool flg = true;
            for(int j = 0; j < lenNeedle;j++){
                if(haystack[j+i] != needle[j]){
                    flg = false;
                    break;
                }
            }
            if(flg){
                return i;
            }
        }
        return -1;
    }
};

// KMP 
// guiding website: https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/575568/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay = haystack.size();
        int lenNeedle = needle.size();

        // build next array
        vector<int> next(lenNeedle,0);
        int j = 0;
        for(int i = 1; i < lenNeedle; i++){
            while(j > 0 && needle[i] != needle[j]){
                j = next[j-1]; // recursively find shorter prefix
            }
            if(needle[i] == needle[j]) j++;
            next[i] = j;
        }

        // kmp searching
        j = 0;
        for(int i = 0; i < lenHay; i++){
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j-1]; //  backtrack based on the next array
            }
            if(haystack[i] == needle[j]) j++;
            if(j == lenNeedle) return i - lenNeedle + 1;
        }
        return -1;
    }
};