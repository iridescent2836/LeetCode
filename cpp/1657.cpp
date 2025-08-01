#include "header.h"

/**
 * Can't pass "uau", "ssx"
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_map<char, int> word1Cnt;
        unordered_map<char, int> word2Cnt;

        for(char ch: word1) word1Cnt[ch]++;
        for(char ch: word2) {
            // to solve bug on input: "uau", "ssx"
            if(word1Cnt.find(ch) == word1Cnt.end()) return false;
            word2Cnt[ch]++;
        }

        unordered_map<int, int> word1FrequencyCnt;
        for(const auto& [ch, cnt] : word1Cnt) {
            word1FrequencyCnt[cnt] ++;
        }

        for(const auto& [ch, cnt] : word2Cnt){
            if(word1FrequencyCnt.find(cnt) == word1FrequencyCnt.end() 
            || word1FrequencyCnt[cnt] == 0) return false;

            word1FrequencyCnt[cnt]--;
        }
        return true;
    }
};

/**
 * a refined version, the idea is the same. 
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (char c : word1) {
            count1[c - 'a']++;
        }
        for (char c : word2) {
            if(count1[c-'a'] == 0) return false;
            count2[c - 'a']++;
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return count1 == count2;
    }
};

