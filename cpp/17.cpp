#include "header.h"

class Solution {
public:
    unordered_map<int, string> number2char{
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };
    int len;
    void dfs(vector<string>& ret, string& temp, const string& digits, int idx){
        if(idx == len){
            ret.push_back(temp);
            return;
        }
        for(auto ch: number2char[digits[idx] - '0']){
            temp.push_back(ch);
            dfs(ret, temp, digits, idx+1);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string temp;
        len = digits.size();
        if(len == 0) return ret;
        dfs(ret, temp, digits, 0);
        return ret;
    }
};