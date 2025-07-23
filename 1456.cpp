#include "header.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int len = s.size();

        vector<int> mp(26, 0);

        mp['a'-'a'] = 1;
        mp['e'-'a'] = 1;
        mp['i'-'a'] = 1;
        mp['o'-'a'] = 1;
        mp['u'-'a'] = 1;


        // init the window
        for(int i = 0; i < k; i++) {
            count += mp[s[i]-'a'];
        }
        int ret = count;
        for(int i = k; i < len; i++) {
            count += mp[s[i]-'a'];
            count -= mp[s[i-k]-'a'];
            ret = ret > count ? ret : count;
        }
        return ret;
    }
};