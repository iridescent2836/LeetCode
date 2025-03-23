#include "header.h"

class Solution {
public:
    void helper(vector<string>& ans, string& temp, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(temp);
            return;
        }
        if(left > 0){
            temp.push_back('(');
            helper(ans,temp,left-1,right);
            temp.pop_back();
        }
        if(right > left){
            temp.push_back(')');
            helper(ans,temp,left,right-1);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(ans,temp, n,n);
        return ans;
    }
};
