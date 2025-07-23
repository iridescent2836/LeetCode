#include "header.h"

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(char ch: s){
            if(ch != '*') stk.push(ch);
            else stk.pop();
        }
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    string removeStars(string s) {
        string res;
        for (char ch : s) {
            if (ch == '*') res.pop_back();
            else res += ch;
        }
        return res;
    }
};

/**
 * 原地修改
 */


class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                next--;
            else
                s[next++] = s[i];
        }
        s = s.substr(0, next);
        return s;
    }
};
