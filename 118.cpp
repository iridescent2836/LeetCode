#include "header.h"


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i = 0; i < numRows; i++){
            int numPerRow =  i + 1;
            vector<int> temp(numPerRow, 1);
            for(int j = 1; j < numPerRow-1; j++){
                temp[j] = ret[i-1][j-1] + ret[i-1][j];
            }

            ret.push_back(temp);
        }
        return ret;
    }
};
