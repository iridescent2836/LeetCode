#include <string>
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
    
        auto len {s.size()};
        if(len < 2){
            return s;
        }
        //初始化
        vector<vector<bool>> db(len,vector<bool>(len));
        int maxLen = 1;
        int begin = 0;
        //默认所有长度为1的子串为回文串
        for(int i = 0;i < len;i++){
            db[i][i] = true;
        }
        
        //对回文子串的可能长度遍历
        for(int L  = 2;L <= len;L++){
            //遍历子串左边界
            for(int i = 0 ;i < len ; i++)
            {
                //子串右边界越界
                int j = i + L - 1;
                if(j >= len){
                    break;
                }

                //子串首尾不等，其一定不是回文串，
                if(s[i]!=s[j]){
                    db[i][j] = false;
                }
                else{
                    //子串长度小于等于三，其一定是回文串
                    if(L <= 3){
                        db[i][j] = true;
                    }
                    //子串是否为回文串与其去除左右边界后的子串一致
                    else{
                        db[i][j] = db[i+1][j-1];
                    }
                }
                //如果该字串是回文串，比较并更新最大值
                if(db[i][j] && L > maxLen){
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};

// Where did I get this answer from? 
class Solution {
public:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len;
            if (right >= i) {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};
    
    