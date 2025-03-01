#include "header.h"
#include "unordered_map"


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> count(52,0);
        // we assume word only contains capital letters and small letters
        int idx = 0;
        for(auto line : board){
            for(char ch: line){
                if (ch >= 'a' && ch <= 'z') { 
                    idx = ch - 'a'; 
                } else if (ch >= 'A' && ch <= 'Z') { 
                    idx = ch - 'A' + 26; 
                }
                count[idx]++;
            }
        }

        for(char ch: word){
            if (ch >= 'a' && ch <= 'z') {
                idx = ch - 'a'; 
            } else if (ch >= 'A' && ch <= 'Z') { 
                idx = ch - 'A' + 26; 
            }
            if(count[idx] < 0) return false;
        }

        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w, 0));
        
        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == word[0]) {
                    // Stack to simulate recursion
                    stack<tuple<int, int, int, int>> stk;
                    stk.push({i, j, 0, 0}); // (i, j, k, direction_index)
                    
                    while (!stk.empty()) {
                        auto [x, y, k, dir_idx] = stk.top();
                        stk.pop();
                        
                        if (k == word.length() - 1) {
                            return true;
                        }
                        
                        if (dir_idx == 0) {
                            visited[x][y] = 1;
                        }
                        
                        if (dir_idx < directions.size()) {
                            int newi = x + directions[dir_idx].first;
                            int newj = y + directions[dir_idx].second;
                            
                            stk.push({x, y, k, dir_idx + 1});
                            
                            if (newi >= 0 && newi < h && newj >= 0 && newj < w) {
                                if (!visited[newi][newj] && board[newi][newj] == word[k + 1]) {
                                    stk.push({newi, newj, k + 1, 0});
                                }
                            }
                        } else {
                            visited[x][y] = 0;
                        }
                    }
                }
            }
        }
        
        return false;
        
    }
};

class Solution {
public:

    bool dfs(vector<vector<bool>>& v, vector<vector<char>>& board,string& s,int i,int j)
    {
        if(v[i][j]==0&&board[i][j]==s[num])
        {
            v[i][j] = true;
            num++;
            if(num==s.size())
            return true;
            // left
            if(i>0)
            {
                bool ret = dfs(v,board,s,i-1,j);
                if(ret)
                return true;
            }
            //right
            if(i<v.size()-1)
            {
                bool ret = dfs(v,board,s,i+1,j);
                if(ret)
                return true;
            }
            //up
            if(j>0)
            {
                bool ret = dfs(v,board,s,i,j-1);
                if(ret)
                return true;
            }
            //down
            if(j<v[0].size()-1)
            {
                bool ret = dfs(v,board,s,i,j+1);
                if(ret)
                return true;
            }
            num--;
            v[i][j] = false;
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word)
    {
        unordered_map<char,int> m;
        for(auto& row : board)        
        {
            for(char col : row)
            {
                m[col]++;
            }
        }

        unordered_map<char,int> word_m;
        for(char c : word)
        {
            if(++word_m[c] > m[c])
            return false;
        }

        if(word_m[word[0]]>word_m[word.back()])
        {
            reverse(word.begin(),word.end());
        }

        num = 0;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> v(row,vector<bool>(col));
        for(int i = 0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(dfs(v,board,word,i,j))
                return true;
            }
        }
        return false;
    }
    int num;
};

int main(){
    Solution solution;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    string word = "ABCB";

    bool ans = solution.exist(board, word);
    if(ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}