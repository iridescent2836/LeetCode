#include "header.h"

// too much time, but correct
class Solution1 {
public:
    int currNum;
    int minNum;

    void helper(string &s, int begin, int end){
        if(begin > end){
            if(currNum - 1 < minNum) minNum = currNum - 1;
            return;
        }
        
        bool isPalindrome;
        // check if s[begin,...,i] is a palindrome
        for(int i = begin; i <= end; i++){
            isPalindrome = true;
            for(int j = 0; j <= i-begin; j++){
                if(s[i-j]!=s[begin+j]){
                    isPalindrome = false;
                    break;
                }
            }
            if(!isPalindrome) continue;

            // is s[begin,..., i] is a palindrome, recursively judge s[i+1,..,end]
            currNum++;
            helper(s,i+1,end);
            currNum--;

        }
        return;
    }

    int minCut(string s) {
        int end = s.size() - 1;
        currNum = 0; // 当前的回文串段数
        minNum = INT32_MAX; // 能切的回文段最小段数，初始化为一个极大值
        helper(s, 0, end);
        return minNum;
    }
};

// dp
// excellent methods. 2 dp: one to decide if the substring is palindrome, 
// another to calculate the min cut
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> isPalindrome(len, vector<bool>(len,true));

        // isPalindrome[i][j] == true iff s[i...j] is palindrome
        // to know s[i,...,j], you have to know s[i+1, ..., j-1] in advance.
        // hence i should goes from high to low
        for(int i  = len-1; i >=0; i--){
            for(int j = i+1; j < len; j++){
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
            }
        }

        // f[n] is the minimum number of cut to make s[0...n] be 
        // divided into palindromes

        vector<int> f(len, INT32_MAX);
        for(int i = 0; i < len; i++){
            if(isPalindrome[0][i]) f[i] = 0;
            else{
                for(int j = 0; j < i; j++){
                    if(isPalindrome[j+1][i]){
                        f[i] = min(f[i], f[j]+1);
                    }
                }
            }
        }
        return f[len-1];
    }
};



int main(){
    Solution s;
    s.minCut("aab");
}