#include "header.h"

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stk;
        string res;
        int multi = 0;

        for(char ch : s){
            if(ch == '['){
                // store the last frame, do the inside
                stk.push({multi, res});
                res = "";
                multi = 0;
            }else if(ch == ']'){
                // restore the last frame, add the current res to the end
                auto [cur_multi, last_res] = stk.top();
                stk.pop();
                string temp = "";
                for (int i = 0; i < cur_multi; i++) {
                    temp += res;
                }
                res = last_res + temp;
            }else if(isdigit(ch)){

                multi = multi * 10 + (ch-'0');
            }
            else {
                res += ch;
            }
        }
        return res;
    }
};

class Solution {
private:
    string dfs(const string & s, int & i){
        string res;
        int multi = 0;
        while(i < len){
            char ch = s[i];
            if(isdigit(ch)){
                multi = multi* 10 + (ch - '0');

            }else if(ch == '[') {
                i++;
                string tmp = dfs(s,i);
                for(int j = 0; j < multi; j++){
                    res += tmp;
                }
                multi = 0;
            } else if(ch==']'){
                return res;
            } else {
                res += ch;
            }
            i++;
        }
        return res;
    }

    int len;
public:
    string decodeString(string s) {
        int i = 0;
        len = s.size();
        return dfs(s, i);
    }
};

