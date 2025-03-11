#include "header.h"
#include <sstream>

class Solution {
public:
    vector<string> split(const string& s, char delim){
        vector<string> ans;
        string curr;
        for(char ch : s){
            if(ch == delim){
                if(!curr.empty()){
                    ans.push_back(move(curr));
                    curr.clear();
                }
            } else {
                curr += ch;
            }
        }

        if(!curr.empty())
            ans.push_back(move(curr));
        return ans;
    }

    string simplifyPath(string path) {
        vector<string> splitPath = split(path, '/');
        vector<string> stk;
        for(auto curr: splitPath){
            if(curr == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            } 
            else if (!curr.empty() && curr != "."){
                stk.push_back(curr);
            }
        }
        string ans;
        if(stk.empty()){
            ans = "/";
        } else {
            for(string& name: stk){
                ans += "/" + move(name);
            }
        }

        return ans;
    }
};

// string stream
class Solution {
public:

    string simplifyPath(string path) {
        vector<string> stk;
        istringstream ss(path);
        string s;
        while(getline(ss, s, '/')){
            if(s.empty()||s == ".") continue;
            else if(s == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }
            else stk.push_back(s);
        }

        if(stk.empty()) return "/";
        
        string ans;
        for(string temp: stk){
            ans += '/';
            ans += temp;
        }
        return ans;
    }
};