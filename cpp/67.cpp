#include "header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        // 进位 
        int c = 0;
        int numa = 0;
        int numb = 0;
        for(int ia = a.size() - 1, ib = b.size() - 1;ia >= 0 || ib >= 0; ia--,ib--) {
            // A good way to avoid checking whether a or b is empty.
            numa = ia >= 0 ? a[ia] - '0' : 0;
            numb = ib >= 0 ? b[ib] - '0' : 0;
            ans.push_back(numa ^ numb ^ c + '0');
            c = (numa & numb) | (c & (numa ^ numb));
        }
        if(c)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};