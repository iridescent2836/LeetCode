#include "header.h"

// clever part: using idx to avoid duplicate arrangings.
class Solution {
public:
    int len;
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, const vector<int>& candidates, int idx){
        if(target == 0){
            ret.push_back(temp);
            return;
        }


        for(int i = idx; i < len; i++){
            if(target-candidates[i] < 0) continue;
            temp.push_back(candidates[i]);
            helper(ret,temp,target - candidates[i], candidates,i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> temp;
        this->len = candidates.size();
        helper(ret, temp, target, candidates, 0);
        return ret;
    }
};