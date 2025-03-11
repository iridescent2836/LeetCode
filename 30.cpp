#include "header.h"
#include <unordered_map>


// O(M*N)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words.size();
        int len = words[0].size();
        int size = num*len;
        int Slen = s.size();

        if(Slen < size) return vector<int>();

        unordered_map<string, int> tbl;

        for(int i = 0; i < num; i++){
            tbl[words[i]]++;
        }

        vector<int> ans;
        // i is the beginning of the substring
        for(int begin = 0; begin < Slen - size + 1; begin++){
            unordered_map<string,int>seen;            
            int matched = 0;

            for(int i = begin; i < begin+size-len+1; i += len){
                string word = s.substr(i,len);
                auto iter = tbl.find(word);
                if(iter == tbl.end()) break;

                seen[word]++;
                if(seen[word] > tbl[word]) break;
                matched++;
            }

            if(matched == num) ans.push_back(begin);
        }   
        return ans;
    }
};


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words.size();
        int len = words[0].size();
        int size = num*len;
        int Slen = s.size();

        if(Slen < size) return vector<int>();
        
        vector<int> ans;

        for(int i = 0; i < len && i + size - 1 < Slen; i++){
            unordered_map<string,int>differ;

            for(int j = 0; j < num; j++){
                differ[s.substr(i+j*len, len)]++;
            }

            // notice, if word doesn't exist in differ, the unordered_map will init 
            // differ[word] = 0, then --differ[word] == -1, which indicate that it 
            // lack word.
            for(auto word:words){
                if(--differ[word] == 0) differ.erase(word);
            }
            // check if the init window satisfy the requiremnet
            if(differ.empty()) ans.push_back(i);

            // start slide
            for(int left = i + len; left < Slen -size+1;left += len){
                // the word that is newly entered the window
                string word = s.substr(left+size-len,len);
                if(++differ[word] == 0) differ.erase(word);
                // the word that has left the window
                word = s.substr(left-len,len);
                if(--differ[word] == 0) differ.erase(word);
                if(differ.empty()) ans.push_back(left);
            }
        }
        return ans;
    }
};