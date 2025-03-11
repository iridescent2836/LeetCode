#include "header.h"

class Solution {
public:
    // translate index into the position at the board. 
    pair<int,int> id2rc(int id, int n){
        int r = (id - 1) / n;
        int c = (id - 1) % n;
        if(r % 2 == 1) c = n - 1 - c;
        return {n - 1 - r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int boundary = n*n;
        vector<int> vis(boundary,false);
        queue<pair<int,int>> q; // q(i,j) means current idx = i, and current step = j;
        q.emplace(1,0);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0; i <= 6; i++){
                int next = curr.first+i;
                
                if(next > boundary) break; // exceed the boundary, break;
                auto rc = id2rc(next,n); // the coordinate of next position
                // snake or ladder exists, go to another position directly
                if(board[rc.first][rc.second]>0){
                    next = board[rc.first][rc.second];
                } 
                if(next == boundary) return curr.second+1;
                if(!vis[next]){
                    vis[next] = true;
                    q.emplace(next, curr.second+1);
                }

            }
        }
        return -1;
    }
};