#include "header.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) {
            return s;
        }
        
        // apply the Zigzag arrangement
        // The number of characters before the next vertical line begins.
        int sizeDecider = numRows + numRows - 2;
        int len = s.size();

        int numBlocks = len / sizeDecider;
        int colsPerBlock = numRows - 1;

        int numOfElementLeft = len % sizeDecider;
        int extraCols = 0;

        if(numOfElementLeft == 0) {
            extraCols = 0;
        }
        else if(numOfElementLeft && numOfElementLeft <= numRows) {
            extraCols = 1;
        } else{
            extraCols = numOfElementLeft - numRows + 1;
        }
        
        // the num of cols
        int cols = numBlocks * colsPerBlock + extraCols;
        
        // init empty matrix
        vector<string> matrix(numRows, string(cols, 0));

        // applying the arrangement
        bool ifGoDown = true;
        int rowidx = 0;
        int colidx = 0;
        // traverse each character

        for(int i = 0; i < len; i++){
            matrix[rowidx][colidx] = s[i];
            if(i % sizeDecider < numRows - 1){
                ++rowidx; // go down
            } else {
                --rowidx;
                ++colidx;
            }

        }

        
        // read the new string
        string ans;
        for (auto &row : matrix) {
            for (char ch : row) {
                if(ch) {
                    ans += ch;
                }
            }
        }
        // return the answer
        return ans;
    }
};