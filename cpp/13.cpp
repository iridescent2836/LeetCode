#include "header.h"

class Solution {
private:
    unordered_map<char, int> romanNumbers{
        {'I', 1   },
        {'V', 5   },
        {'X', 10  },
        {'L', 50  },
        {'C', 100 },
        {'D', 500 },
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        for(int i = 0; i < len-1; i++){
            int curr = romanNumbers[s[i]];
            int next = romanNumbers[s[i+1]];
            ans += (curr >= next ? curr : -curr);
        }
        ans += romanNumbers[s[len-1]];
        return ans;
    }
};