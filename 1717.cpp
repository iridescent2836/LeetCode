#include "header.h"


/**
 * simple but correct method. 
 * 模拟删除 "ab", "ba" 的过程
 * time: O(n^2)
 * space: O(1)
 */
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string larger = x > y ? "ab" : "ba";
        int largerNum = x > y ? x : y;
        string smaller = x > y ? "ba" : "ab";
        int smallerNum = x > y ? y : x;
        int score = 0;
        bool isModified = false;
        while(true) {
            isModified = false;
            for(int i = 0; i < s.size()-1; i++) {
                if(s.substr(i, 2)  == larger) {
                    s = s.substr(0, i) + s.substr(i+2, s.size() - i - 2);
                    score += largerNum;
                    isModified = true;
                    break;
                }
            }
            if(isModified) continue;
            for(int i = 0; i < s.size()-1; i++) {
                if(s.substr(i, 2)  == smaller) {
                    s = s.substr(0, i) + s.substr(i+2, s.size() - i - 2);
                    score += smallerNum;
                    isModified = true;
                    break;
                }
            }
            if(!isModified) break; 
        }
        return score;
    }
};


/**
 * 不妨假设得分 "ab" > "ba" 
 * 否则交换 a, b 和 x, y 即可
 * 
 * 我们要贪心的先删除 "ab"
 * 
 * 对于只有 a, b 组成的字串
 * 
 * 每次删除操作都会使字符串中‘a’和‘b’的数量减少一个，且剩余字母的相对位置不变。不妨假设删除“ab”，考虑相邻的前后两个字母，可能有以下情况：
 * 前后两个字母相同，即操作前的字符串是“aaba”或“babb”，删除“ab”后会剩余两个相同字母，无法进行删除，因此在删除前后，总删除次数不变。
 * 前后的字母是“ab”，即操作前的字符串是“aabb”，则在删除“ab”后可以再进行一次删除，因此在删除前后，总删除次数不变。
 * 前后的字母是“ba”，即操作前的字符串是“baba”，则在删除“ab”后可以再进行一次删除，因此在删除前后，总删除次数不变。
 */
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if(x < y) {
            swap(x, y);
            swap(a, b);
        }

        int score = 0, cnt_a = 0, cnt_b = 0;
        int len = s.size();
        for(char ch : s) {
            if(ch == a) {
                cnt_a++;
            } else if (ch == b) {
                if(cnt_a > 0) {
                    // “删除” ab
                    score += x;
                    cnt_a--;
                } else {
                    cnt_b++;
                }
            } else {
                // 把剩下的 ba 都删除掉
                score += min(cnt_a, cnt_b) * y;
                cnt_a = 0;
                cnt_b = 0;
            }
        }

        score += min(cnt_a, cnt_b) * y;
        return score;
    }
};


/**
 * 用栈模拟
 * time: O(n)
 * space: O(n)
 */
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if(x < y) {
            swap(x, y);
            swap(a, b);
        }

        
        stack<char> stk;
        int score = 0;
        stk.push('f');
        for(char ch: s){
            if(ch == a) {
                stk.push(ch);
            } else if(ch == b){
                if(stk.top() == a) {
                    stk.pop();
                    score += x;
                } else {
                    stk.push(ch);
                }
            } else {
                stack<char> stk_temp;
                stk_temp.push('f');
                char temp;
                while(stk.top() == a || stk.top() == b){
                    // delete all "ba"
                    while(stk_temp.top() == a && stk.top() == b) {
                        score += y;
                        stk_temp.pop();
                        stk.pop();
                    }


                    if(stk.top() == a || stk.top() == b){
                        temp = stk.top();
                        stk.pop();
                        stk_temp.push(temp);
                    }
                    
                }
                stk.push(ch);
            }
        }


        stack<char> stk_temp;
        stk_temp.push('f');
        char temp;
        while(stk.top()== a || stk.top() == b){
            // delete all "ba"
            while(stk_temp.top() == a && stk.top() == b) {
                score += y;
                stk_temp.pop();
                stk.pop();
            }
            if(stk.top() == a || stk.top() == b){
                temp = stk.top();
                stk.pop();
                stk_temp.push(temp);
            }
        }
        return score;
    }
};
