#include "header.h"


class Solution {
public:

    void helper(int begin, int n, int k, vector<int>& ans, vector<vector<int>>& finalAns){
        if(k == 0){
            finalAns.push_back(ans);
            return;
        }
        if(begin + k - 1 > n) return;
        
        for(int i = begin;i <= n; i++){
            ans.push_back(i);
            helper(i+1, n, k-1, ans, finalAns);
            ans.pop_back();
        }
        return;
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        helper(1,n,k,ans,finalAns);
        return finalAns;
    }
};


int main(){
    Solution s;
    vector<vector<int>> ans = s.combine(9,3);
    for(auto i : ans){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}