#include "header.h"

// this method used dfs to traverse the map, and using bfs is similar
class Solution {
public:
    void dfs(vector<bool>& visited, int city,const int& num, const vector<vector<int>>& isConnected){
        visited[city] = true;
        for(int i = 0; i < num; i++){
            if(isConnected[city][i] && !visited[i]) dfs(visited, i, num, isConnected);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = isConnected.size();
        vector<bool> visited(num, false);
        int count = 0;
        for(int i = 0; i < num; i++){
            if(!visited[i]){
                count++;
                dfs(visited, i, num, isConnected);
            }
        }
        return count;
    }
};

// using disjoint set
class Solution {
public:
    int Find(vector<int>& parent, int index) {
        // if not the root. 
        // root has a feature that: parent[root] == root
        if(parent[index] != index){
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> parent(cities);
        for(int i = 0; i < cities; i++){
            parent[i] = i;
        }
        for(int i = 0; i < cities-1; i++){
            for(int j = i + 1; j < cities; j++){
                if(isConnected[i][j]) Union(parent, i,j);
            }
        }
        int provinces = 0;
        for(int i = 0; i < cities; i++){
            if(parent[i] == i) provinces++;
        }
        return provinces;
    }
};