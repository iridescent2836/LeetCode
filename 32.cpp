#include "header.h"

void pringVector(vector<int> vec) {
    for(auto itm : vec) {
        cout << itm << ' ';
    }
    cout << '\n';
}


/**
 * Wrong method. seem to work. 
 * but cannot solve "()(()"
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int ret = 0;
        vector<int> left_par(len+1, 0);
        vector<int> valid_par(len+1, 0);
        for(int i = 0; i < len; i++) {
            i++;
            if(s[i-1] == '(') {
                // valid_par[i] = valid_par[i-1];
                left_par[i] = left_par[i-1] + 1;
            } else if(s[i-1] == ')') {
                if(left_par[i-1] == 0){
                    i--;
                    continue;
                }
                if(left_par[i-1] > 0){
                    valid_par[i] = valid_par[i-1] + 1;
                    if(valid_par[i] > ret) ret = valid_par[i];
                    left_par[i] = left_par[i-1] - 1;
                }

            }
            // pringVector(left_par);
            pringVector(valid_par);
            i--;
        }
        return ret * 2;
    }
};


/**
 * dp[i] 表示以 s[i] 结尾的最长的有效括号对长度
 * dp
 * 如果是"...()"，则 dp[i] = dp[i-2] + 2
 * 
 * 如果是 "...))"，
 *    如果 s[i-1 -dp[i-1]] = '(' -> s[i-1-dp[i-1]] 和 s[i] 可以组成一个新的有效括号对
 *        则 dp[i] = dp[i-1] + dp[i-1 -dp[i-1] -1] + 2;
 * 
 * 不理解这些index是怎么得到的就看同题号的jpg
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int ret = 0;
        vector<int> dp(len, 0);
        for(int i = 1; i < len; i++) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            ret = dp[i] > ret ? dp[i] : ret;
        }
        return ret;
    }
};

/**
 * use stack
 * 保持栈底为最后一个未被匹配的右括号index
 * 为什么？因为多余的右括号不可能和之后的括号形成一个合法的括号字串，所以它应该作为一个分隔位置的作用。
 * 比如 () )))) ()
 * 初始栈底为-1
 * time: O(n)
 * space: O(1)
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int ret = 0;
        int curr = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }else {
                stk.pop();
                if(stk.empty()) {
                    stk.push(i);
                } else {
                    ret = max(ret, i - stk.top());
                }
            }
        }
        return ret;
    }
};

/**
 * time: O(2n)
 * space: O(1)
 * 
 * 
 * 用两个计数器 left 和 right。
 * 首先从左到右遍历字符串，对于遇到的每个 ‘(’，我们增加 left 计数器，对于遇到的每个 ‘)’ ，我们增加 right 计数器。
 * 
 * 当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。
 * 当 right 计数器比 left 计数器大时，我们将 left 和 right 计数器同时变回 0。
 * 
 * 这样的做法贪心地考虑了以当前字符下标结尾的有效括号长度，每次当右括号数量多于左括号数量的时候之前的字符我们都扔掉不再考虑，
 * 重新从下一个字符开始计算，但这样会漏掉一种情况，就是遍历的时候左括号的数量始终大于右括号的数量，
 * 即 (() ，这种时候最长有效括号是求不出来的。
 * 
 * 解决的方法也很简单，我们只需要从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来：
 * 
 * 当 left 计数器比 right 计数器大时，我们将 left 和 right 计数器同时变回 0
 * 当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串
 * 
 * 和我自己尝试的思路很像，但是更聪明。
 */


class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int ret = 0;
        int left = 0;
        int right = 0;

        for(int i = 0; i < len; i++) {
            if(s[i] == '(') left++;
            else right++;
            if(right > left) left = right = 0;
            if(left == right) ret = max(ret, left << 1);
        }

        left = right = 0;
        for(int i = len-1; i >=0; i--) {
            if(s[i] == '(') left++;
            else right++;
            if(right < left) left = right = 0;
            if(left == right) ret = max(ret, left << 1);
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    string s = "()(()";
    cout << sol.longestValidParentheses(s);
    return 0;

}