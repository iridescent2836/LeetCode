#include "header.h"

void printVec(const vector<int> & vec){
    for(auto item: vec){
        cout << item << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    void helper(int k, int n, vector<int> & tmp, vector<vector<int>> & ans, int curr) {
        if(n  < 0) return;
        if(n == 0 && k == 0){
            ans.push_back(tmp);
            return;
        }

        for(int i = curr; i < 10; i++){
            tmp.push_back(i);
            helper(k-1, n-i, tmp, ans, i+1 );
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(k, n, tmp, ans, 1);
        return ans;
    }
};
int main() {
    Solution s;
    s.combinationSum3(3,7);
}