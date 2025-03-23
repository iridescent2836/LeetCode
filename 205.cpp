#include "header.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS != lenT) return false;

        
        unordered_map<char,char> mapStoT;
        unordered_map<char, char> mapTtoS;
        for(int i = 0; i < lenS; i++){
            // no such map, create it
            if(!mapStoT.count(s[i]) && !mapTtoS.count(t[i])){
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            } 
            // such map exists, check if it was legal
            else {
                if(mapStoT[s[i]] != t[i] || mapTtoS[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};

// optimize for the situation in this question:
// for char has at most 256 characters, we use vector instead of unordered_map
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if(lenS != lenT) return false;

        vector<int> mapStoT(256,-1);
        vector<int> mapTtoS(256,-1);
        for(int i = 0; i < lenS; i++){
            // no such map, create it
            if(mapStoT[s[i]] == -1 && mapTtoS[t[i]] == -1){
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            } 
            // such map exists, check if it was legal
            else {
                if(mapStoT[s[i]] != t[i] || mapTtoS[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};