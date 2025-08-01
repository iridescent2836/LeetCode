#include "header.h"


/**
 * Build the map, then search it.
 * 
 * I successfully figured out the method, 
 * but failed to find the suitable data
 * structure for it. Hence the reference
 * to online solutions is helpful. 
 * 
 * Besides, the official solution SUCKS. 
 */
class Solution {
private:
    unordered_map<string, unordered_map<string, double>> map;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len_vals = equations.size();
        for(int i = 0; i < len_vals; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];
            map[u][v] = weight;
            map[v][u] = 1.0 / weight;
        }

        int len_queries = queries.size();
        vector<double> results(len_queries, -1.0);
        for(int i = 0; i < len_queries; i++){
            string start = queries[i][0];
            string end = queries[i][1];

            if(!map.count(start) || !map.count(end)) continue;

            if(start == end) {
                results[i] = 1.0;
                continue;
            }

            // use bfs to search the map
            queue<pair<string, double>>qu;
            unordered_map<string, bool> visited;
            qu.push({start, 1.0});
            visited[start] = true;
            while(!qu.empty()){
                string curr = qu.front().first;
                double currVal = qu.front().second;
                qu.pop();

                if(curr == end){
                    results[i] = currVal;
                    break;
                }

                for(auto neighbor : map[curr]){
                    string next = neighbor.first;
                    double nextVal = neighbor.second;
                    if(!visited[next]){
                        visited[next] = true;
                        qu.push({next, currVal * nextVal});
                    }
                }

            }
        }
        return results;
    }
};