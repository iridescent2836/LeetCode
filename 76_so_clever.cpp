#include "header.h"

// we use slide window
// this is a clever clever implementation. 
class Solution {
public:

    string minWindow(string s, string t) {
        int ht[256] = {0}, hs[256] = {0};
        // nums[left...right] has the substring that covers t

        int lenS = s.size();
        int lenT = t.size();
        string ret;
        for(int i = 0; i < lenT; i++){
            ht[t[i]]++;
        }
        int count = 0;
        for(int left = 0, right = 0;right < lenS; right++){
            hs[s[right]]++;
            // means that adding this letter is benifitial for 
            // covering `t`, hence, we add `count`
            if(hs[s[right]] <= ht[s[right]]) count++; 
            
            //try to shrink the window
            while(hs[s[left]] > ht[s[left]]){
                hs[s[left]]--;
                left++;
            }

            // `t` can be fully covered
            if(count == lenT){
                if(right-left+1 < ret.size() || ret.empty()){
                    ret = s.substr(left, left-right+1);
                }
            }
            
        }
        return ret;
    }
};