#include "header.h"

/**
 * 实际为图的连通问题
 * bfs
 */
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        visited[0] = true;
        int room_count = 1;
        queue<int> qu;
        for(int room: rooms[0]) {
            qu.push(room);
        }

        while(!qu.empty()) {
            int len = qu.size();
            for(int i = 0; i < len; i++) {
                int curr_room = qu.front();
                qu.pop();
                if(!visited[curr_room]){
                    room_count++;
                    visited[curr_room] = true;
                    for(int could_visit: rooms[curr_room]){
                        qu.push(could_visit);
                    }
                }
            }
        }

        return room_count == n;
    }
};

/**
 * dfs
 */

class Solution {
public:
    void helper(vector<bool>& visited, int curr_room, vector<vector<int>>& rooms, int& room_count){
        for(int room: rooms[curr_room]) {
            if(!visited[room]){
                visited[room] = true;
                room_count++;
                helper(visited, room, rooms, room_count);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int room_count=1;
        visited[0] = true;
        helper(visited, 0, rooms, room_count);
        return room_count == n;

    }
};