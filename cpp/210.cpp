// we use adjacency matrix to store the map
#include "header.h"
#include <queue>


// useful but too time wasting. 
class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        for(auto prerequisite: prerequisites){
            int i = prerequisite[1];
            int j = prerequisite[0];
            adj[i][j] = 1;
        }
        int length = 0;
        bool isFirst = true;
        while(length != ans.size() || isFirst){
            isFirst = false;
            length = ans.size();
            // 统计入度为0的点
            for(int j = 0; j < numCourses ; j++){
                if(visited[j]) continue;
                int flg = true;
                for(int i = 0; i < numCourses; i++){
                    // 有入度
                    if(adj[i][j]){
                        flg = false;
                        break;
                    }
                }
                // 添加到路径中，并且更新邻接矩阵
                if(flg){
                    ans.push_back(j);
                    visited[j] = 1;
                    for(int i = 0; i < numCourses; i++)
                        adj[j][i] = 0;
                    
                    for(auto an : ans)
                        cout << an << ' ';
                    cout << endl;
                }
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return vector<int>();
    }
};

// 引入其它数据结构来存储图
class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> edges(numCourses, vector<int>());
        // 存储入度
        vector<int> inedges(numCourses, 0);
        vector<int> ans;
        queue<int> temp;


        for(auto prerequisite: prerequisites){
            edges[prerequisite[1]].push_back(prerequisite[0]);
            inedges[prerequisite[0]]++;
        }
        

        for(int i = 0; i < numCourses ; i++){
            if(!inedges[i]) temp.push(i);
        }

        while(!temp.empty()){
            int current = temp.front();
            temp.pop();
            for(auto v: edges[current]){
                inedges[v]--;
                if(!inedges[v]){
                    temp.push(v);
                }
            }
            ans.push_back(current);
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
    


int main(){
    vector<vector<int>> prerequisites = {{3,0},{0,1}};
    Solution s = Solution();
    s.findOrder(4,prerequisites);
    return 0;

}