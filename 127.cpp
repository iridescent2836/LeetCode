#include "header.h"

// bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSets;
        unordered_set<string> visit;

        for(auto& word: wordList){
            wordListSets.insert(word);
        }

        if(!wordListSets.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string word = q.front();
                q.pop();
                int len = word.size();
                // change each letter, see if it will work. 
                for(int j = 0; j < len; j++){
                    // check if modified a char is still a word in wordList. 
                    for(int k = 0; k < 26; k++){
                        string temp = word;
                        if(temp[j] == 'a'+k) continue;
                        temp[j] = 'a'+k;

                        if(temp == endWord) return ++step;
                        if(wordListSets.count(temp) != 0 && visit.count(temp) == 0){
                            visit.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};