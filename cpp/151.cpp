#include "header.h"

// only basc methods: finite state automaton
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        vector<pair<int,int>> words;

        // get words
        int begin = 0;
        bool state = s[0] == ' '; // false: getting words; true: encountering space
        while(begin < len){
            if(!state){
                // get the beginning and end idx of word
                int right = begin;
                while(right < len && s[right] != ' ') right++;
                words.push_back({begin, right-1});
                begin = right;
                state = !state;
            } else {
                // skip spaces
                while(begin < len && s [begin] == ' ') begin++;
                state = !state;
            }
        }

        // reverse words
        int numWords = words.size();
        string ans;
        for(int i = numWords - 1; i >= 0; i--){
            ans += s.substr(words[i].first, words[i].second - words[i].first + 1);
            if(i != 0) ans += " ";
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str = "   hello world   ";
    string ans = s.reverseWords(str);
    cout << ans << endl;
    return 0;
}