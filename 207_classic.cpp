#include "header.h"

/**
 * 拓扑排序，递归将所有入度为0的点删除
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <= 1 || prerequisites.size() <= 1) return true;
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);

        // the edge is : prerequisite[1] -> prerequisite[0]
        for(const auto & prerequisite: prerequisites){
            graph[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++;
        }
        
        queue<int> temp;
        for(int i = 0; i < numCourses; i++){
            if(in_degree[i] == 0) temp.push(i);
        }

        int det = 0;

        while(!temp.empty()){
            int to_delete = temp.front();
            temp.pop();
            det++;
            for(auto i : graph[to_delete]){
                in_degree[i]--;
                if(in_degree[i] == 0){
                    temp.push(i);
                }
            }
        }

        return det == numCourses;
    }
};