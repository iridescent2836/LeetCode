#include "header.h"


// to much time, but correct
class Solution {
public:
    bool helper(vector<vector<char>>& board,vector<vector<bool>>& visited, string & word, int i, int j ,int& idx ){
        if(!visited[i][j] && board[i][j] == word[idx]){
            idx++;
            if(idx == word.size()) return true;

            visited[i][j] = true;
            bool ret;
            if(i > 0){
                ret = helper(board, visited, word, i-1, j, idx);
                if(ret) return true;
            }
            if(i < board.size()-1){
                ret = helper(board, visited, word, i+1, j, idx);
                if(ret) return true;
            }
            if(j > 0){
                ret = helper(board, visited, word, i, j-1, idx);
                if(ret) return true;
            }
            if(j < board[0].size()-1){
                ret = helper(board, visited, word, i, j+1, idx);
                if(ret) return true;
            }
            visited[i][j] = false;
            idx--;
        }
        return false;

    }

    bool findWord(vector<vector<char>>& board, string& word){
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int startIdx = 0;
                if(helper(board, visited, word, i, j, startIdx)) return true;
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        unordered_map<char, int> board_m;
        for(auto row: board){
            for(auto ch: row){
                board_m[ch]++;
            }
        }
        for(string word: words){
            
            unordered_map<char, int>word_m;
            for(char ch: word){
                if(word_m[++ch] > board_m[ch]) continue;
            }
            if(word_m[word[0]]>word_m[word.back()])
            {
                reverse(word.begin(),word.end());
            }

            if(findWord(board, word)) ans.push_back(word);
        }
        return ans;
    }
};




struct TrieNode
{
    string word; // only the leaf will have this property
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        this->word = "";
    }
};

void insertWord(TrieNode* root, const string & word){
    
    TrieNode* node = root;
    for(char ch : word){
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->word = word;
}

class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>> & board, int i, int j,TrieNode* root, set<string>& res){
        int ch = board[i][j];
        if(!root->children.count(ch)) return false;

        root = root->children[ch];
        if(root->word.size() > 0){
            res.insert(root->word);
        }

        // represents that the position has been accessed
        board[i][j] = '#';

        if(i > 0) dfs(board, i-1,j,root,res);
        if(i < board.size()-1) dfs(board,i+1,j,root,res);
        if(j > 0) dfs(board, i,j-1,root,res);
        if(j < board[0].size()-1) dfs(board,i,j+1,root,res);
        board[i][j] = ch;
        return true;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = new TrieNode();
        unordered_map<char, int> board_m;
        for(auto row: board){
            for(auto ch: row){
                board_m[ch]++;
            }
        }            
            
        for(string word: words){
            unordered_map<char, int>word_m;
            int flg = false;
            for(char ch: word){
                if(word_m[++ch] > board_m[ch]){
                    flg = true;
                    break;
                }
            }
            if(flg) continue;
            insertWord(root, word);
        }
        int rows = board.size();
        int cols = board[0].size();
        set<string> res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                dfs(board, i,j,root, res);
            }
        }
        for(auto word:res){
            ans.emplace_back(word);
        }
        return ans;
    }
};