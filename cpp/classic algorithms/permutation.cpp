#include "../header.h"

class permutationUsingSwap {
public:
    void generatePermutations(vector<int> & nums, int start, vector<vector<int>>& result){
        if(start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) continue; // 跳过重复
            swap(nums[i], nums[start]);
            generatePermutations(nums, start+1, result);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);
        return result;
    }
};


class permutationUsingVisited {
public:
    void generatePermutations(const vector<int> & nums, vector<vector<int>>& result, 
                              vector<int>& temp, vector<bool>& visited){
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                generatePermutations(nums,result, temp, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    void generatePermutationsWithoutDuplication(const vector<int> & nums, vector<vector<int>>& result, 
                                                vector<int>& temp, vector<bool>& visited){
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;
            // 去重关键，前提：必须先对nums排序，让相同数字相邻。
            if(i > 0 && nums[i] == nums[i-1] && !visited[nums[i-1]]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            generatePermutations(nums,result, temp, visited);
            temp.pop_back();
            visited[i] = false;
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;
        generatePermutations(nums, result, temp, visited);
        return result;
    }
};