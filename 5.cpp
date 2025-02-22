#include <string>
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
    
        auto len {s.size()};
        if(len < 2)
        {
            return s;
        }
        //初始化
        vector<vector<bool>> db(len,vector<bool>(len));
        int maxLen = 1;
        int begin = 0;
        //默认所有长度为1的子串为回文串
        for(int i = 0;i < len;i++)
        {
            db[i][i] = true;
        }
        
        //对回文子串的可能长度遍历
        for(int L  = 2;L <= len;L++)
        {
            //遍历子串左边界
            for(int i = 0 ;i < len ; i++)
            {
                //子串右边界越界
                int j = i + L - 1;
                if(j >= len)
                {
                    break;
                }

                //子串首尾不等，其一定不是回文串，
                if(s[i]!=s[j])
                {
                    db[i][j] = false;
                }
                else
                {
                    //子串长度小于等于三，其一定是回文串
                    if(L <= 3)
                    {
                        db[i][j] = true;
                    }
                    //子串是否为回文串与其去除左右边界后的子串一致
                    else
                    {
                        db[i][j] = db[i+1][j-1];
                    }
                }
                //如果该字串是回文串，比较并更新最大值
                if(db[i][j] && L > maxLen)
                {
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};