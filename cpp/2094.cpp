#include "header.h"

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;   // 目标偶数集合
        int n = digits.size();
        // 遍历三个数位的下标
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < n; ++k){
                    // 判断是否满足目标偶数的条件
                    if (i == j || j == k || i == k){
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0){
                        nums.insert(num);
                    }
                }
            }
        }
        // 转化为升序排序的数组
        vector<int> res;
        for (const int num: nums){
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;   // 目标偶数数组
        unordered_map<int, int> freq;   // 整数数组中各数字的出现次数
        for (const int digit: digits){
            ++freq[digit];
        }
       // 枚举所有三位偶数，维护整数中各数位的出现次数并比较判断是否为目标偶数
        for (int i = 100; i < 1000; i += 2){
            unordered_map<int, int> freq1;
            int tmp = i;
            while (tmp){
                ++freq1[tmp%10];
                tmp /= 10;
            }
            if (all_of(freq1.begin(), freq1.end(), [&](const auto& x){
                    return freq[x.first] >= freq1[x.first]; 
                })){
                res.push_back(i);
            }
        }
        return res;
    }
};
