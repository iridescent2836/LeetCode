#include "header.h"

class Solution {
public:
    void helper(int n,const int len,vector<int>& visited, const vector<int>& nums, vector<vector<int>>& ans,vector<int>& temp){
        if(n == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < len; i++){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                helper(n-1,len,visited,nums,ans,temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> visited(len, false);
        vector<int> temp;
        helper(len, len, visited,nums,ans,temp);
        return ans;
    }
};