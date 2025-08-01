#include "header.h"
#include <queue>

// brute way
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)
            return 0;
        
        unordered_set<string> cnt;
        unordered_set<string> visited;
        char keys[4] = {'A','C','G','T'};
        for(auto & gene: bank)
            cnt.emplace(gene);
        if(!cnt.count(endGene))
            return -1;
        
        queue<string> q;

        q.emplace(startGene);
        visited.emplace(startGene);
        int step = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                string curr = q.front();
                q.pop();
                // all the possible variants from the current gene
                for(int j = 0; j < 8; j++){
                    for(int k = 0; k < 4; k++){
                        if(keys[k] != curr[j]) {
                            string next = curr;
                            next[j] = keys[k];
                            if(!visited.count(next) && cnt.count(next)){
                                if(next == endGene) return step;
                                q.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

// 将所有的改变可能性存储到邻接表中
// 再用bfs
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int bankSize = bank.size();
        vector<vector<int>> adj(bankSize);
        int endIndex = -1;
        for(int i = 0; i < bankSize;i++){
            if(bank[i] == endGene) endIndex = i;
            for(int j = i+1; j < bankSize; j++){
                int mutations = 0;
                for(int k = 0; k < 8; k++){
                    if(bank[i][k] != bank[j][k]) mutations++;
                    if(mutations > 1) break;
                }
                if(mutations == 1){
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);

                }
            }
        }
        if(endIndex == -1) return -1;


        queue<int> q;
        vector<bool> visited(bankSize, false);
        for(int i = 0; i < bankSize; i++){
            int mutations = 0;
            for(int j = 0; j < 8; j++){
                if(startGene[j]!=bank[i][j]) mutations++;
                if(mutations > 1) break;
            }
            if(mutations == 1){
                q.emplace(i);
                visited[i] = true;
            }
        }

        int step = 1;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){

                int curr = q.front();
                if(curr == endIndex) return step;
                q.pop();

                for(auto next: adj[curr]){
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};