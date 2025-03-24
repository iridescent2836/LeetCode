#include "header.h"

// we use dictionary tree. 
struct node
{
    vector<node*> children;
    bool isEnd;
    node() {
        isEnd = false;
        children = vector<node*>(26, nullptr);
    }
};

class WordDictionary {
private:
    node* root; 
public:
    WordDictionary() {
        root = new node;
    }
    
    void addWord(string word) {
        node* curr = root;
        for(char ch: word){
            int idx = ch - 'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx] = new node;
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool dfs(const string & word, int wordIdx, node* curr,const int& n){
        if(curr == nullptr) return false;

        if(wordIdx == n) return curr->isEnd;
        char ch = word[wordIdx];

        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                if(dfs(word, wordIdx+1, curr->children[i], n)) return true;
            }
        } else {
            return dfs(word, wordIdx+1, curr->children[ch - 'a'], n);
        }
        // this return will be used when (ch == '.') and 
        // no possible substitution of `.` is satisfied. 
        return false; 
    }
    
    bool search(string word) {
        return dfs(word, 0, root, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */