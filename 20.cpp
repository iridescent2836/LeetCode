#include "header.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(stk.size()%2==1) return false; // greatly improve the efficiency of the code. 

        for(char ch:s) {
            if(ch == '(' || ch == '{'  || ch == '[') stk.push(ch);
            else {
                if(stk.empty()) return false;
                char temp = stk.top();
                stk.pop();
                switch (ch)
                {
                case ')':
                    if(temp != '(') return false; 
                    break;
                case '}':
                    if(temp != '{') return false; 
                    break;
                case ']':
                    if(temp != '[') return false; 
                    break;
                default:
                    cerr << "you entered a wrong character" << endl;
                    break;
                }
            }
        }
        return stk.empty();
    }
};

// prettier, but more space version
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len%2==1) return false;

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;
        for(char ch: s) {
            if(pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) return false;
                
                stk.pop();
            }
            else stk.push(ch);
        }
        return stk.empty();
    }
};