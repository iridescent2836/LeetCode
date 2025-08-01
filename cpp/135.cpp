#include "header.h"


// TODO finish it
/*
The question can be simplified to: 
   if ratings[i] > ratings[i-1]
   candy[i] > candy[i-1]


   if ratings[i] > ratings[i+1]
   candy[i] > candy[i+1]
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) {
            return 1;
        }

        vector<int> left(len, 1);
        
        // left to right
        left[0] = 1;
        for(int i = 1; i < len; i++) {
            left[i] = ratings[i - 1] < ratings[i] ?  left[i-1] + 1 : 1;
        }

        // right to left
        int right = 1;
        int ans = 0;
        ans += max(left[len-1], right);
        for(int i = len-2; i >=0; i--) {
            right = ratings[i] > ratings[i + 1] ?  right + 1 : 1;
            ans += max(left[i], right);
        }
        return ans;
    }
};

// 详细解释见官方答案二
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) {
            return 1;
        }

        vector<int> left(len, 1);
        
        // left to right
        left[0] = 1;
        for(int i = 1; i < len; i++) {
            left[i] = ratings[i - 1] < ratings[i] ?  left[i-1] + 1 : 1;
        }

        // right to left
        int right = 1;
        int ans = 0;
        ans += max(left[len-1], right);
        for(int i = len-2; i >=0; i--) {
            right = ratings[i] > ratings[i + 1] ?  right + 1 : 1;
            ans += max(left[i], right);
        }
        return ans;
    }
};


int main() {
    vector<int> ratings = {1,0,2};
    Solution* s = new Solution();
    int ans = s->candy(ratings);
    delete s;
    cout << ans << endl;

    return 0;
}