#include "header.h"

// we use binary search. 
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        else if(x <= 1) return x;

        int l = 0;
        int r = x;
        int ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if((long long) mid * mid <= x){
                ans = mid;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << pow(999.0, 0.5) << endl;

    cout << s.mySqrt(999) << endl;
    return 0;
}