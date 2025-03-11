#include "header.h"

class Solution {
private:
    // create blank
    string blank(int n){
        return string(n, ' ');
    }
    // join words[left, ... , right - 1]
    string join(vector<string>& words, int left, int right, string sep){
        string s = words[left];
        for(int i = left + 1; i < right; i++){
            s += sep + words[i];
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int len = words.size();
        // decide how many word can exist in each line
        int right = 0;
        while(right < len){
            int left = right; // remember the position of the beginning of this line
            int sumLen = 0; // the sum of words' length of this line
            // decide this line has how many words, notice that there are at least 1 space between each
            // pair of words
            while(right < len && sumLen + words[right].length() + right - left <= maxWidth){
                sumLen += words[right].length();
                right++;
            }

            // the last line
            if(right == len){
                string s = join(words,left,right, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth-sumLen; // the number of spaces

            // only one word a line
            if(numWords == 1){
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }

            // more than one word a line
            // numWords - 1 == number of intervals
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1)); // 拼接额外加一个空格的单词
            string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces)); // 拼接其余单词
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
        return ans;
    }
};