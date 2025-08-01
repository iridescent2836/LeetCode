#include "header.h"

// i am smart as fuck. yeah!!!!
class Solution {
public:
    void helper(int begin, int end, string &s , vector<string>& temp, vector<vector<string>>& ans){
        if(begin > end) {
            ans.push_back(temp);
            return;
        };

        bool isPalindrome;
        for(int i = begin; i<=end ;i++){
            isPalindrome = true;
            for(int j = 0; j <= i-begin; j++){
                if(s[begin+j] != s[i-j]){
                    isPalindrome = false;
                    break;
                }
            }
            
            if(!isPalindrome) continue;

            // a Palindrome found, find another
            temp.push_back(s.substr(begin, i-begin+1));
            // cout << s.substr(begin, i-begin+1) << endl;
            helper(i+1,end,s, temp, ans);
            temp.pop_back();


            // cout << ifOk << endl;
        }

        // from begin cannot find another palindrome, clear stack, return. 
        return;

    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int end = s.size()-1;
        vector<string> temp;
        helper(0, end, s, temp, ans);
        return ans;
    }

};


int main(){
    Solution sol;
    string s = "abcdcba";
    vector<vector<string>> ans;
    ans = sol.partition(s);
    for(auto i: ans){
        for(auto j: i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}