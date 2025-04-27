#include "header.h"

// for more detailed explanation, please refer to the leetcode official solution. 
// it's a clever yet clear solution. 
// only the few true smart ones can understand it. 
class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        // set the defaught sign be positive
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int len = s.size();
        int i = 0;
        while(i < len){
            // skip space
            if(s[i] == ' '){
                i++;
            }
            // endounter '+', the sign stays the same
            else if(s[i] == '+'){
                sign = ops.top();
                i++;
            }
            // sign change to the opposite
            else if(s[i] == '-'){
                sign = -ops.top();
                i++;
            }
            // store the current sign
            else if(s[i] == '('){
                ops.push(sign);
                i++;
            }
            // the current sign became useless
            else if(s[i] == ')'){
                ops.pop();
                i++;
            }
            else{
                long num = 0;
                for(;i < len && '0' <= s[i] && s[i] <= '9';i++)
                    num = num * 10 + s[i] - '0';
                ret += sign * num;
            }
        }
        return ret;
    }
};