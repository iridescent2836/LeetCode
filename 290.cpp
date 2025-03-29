#include "header.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int len = s.size();
        int left = 0;
        for(char ch: pattern){
            // if pattern hasn't reach the end while the
            // `s` has reached, then the pattern musn't be matched
            if(left >= len) return false;
            int right = left;
            // find the boundary of the word
            while(right < len && s[right]!=' ') right++;
            const string &temp = s.substr(left, right-left);

            // if each map is not matched, return false;
            if(str2ch.count(temp) && str2ch[temp] != ch) return false;
            if(ch2str.count(ch) && ch2str[ch] != temp) return false;
            // the map has't been created yet, create it. 
            str2ch[temp] = ch;
            ch2str[ch] = temp;
            // the new start position of matching. 
            left = right+1;
        }
        return left >= len;
    }
};