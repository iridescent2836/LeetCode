#include "header.h"

class Solution {
public:
    string intToString(int num){
        if(num == 0) return "0";
        if(num == INT32_MIN) return "-2147483648";

        bool isNegative = num < 0;
        if(isNegative) num = -num;
        string result;
        while(num > 0){
            result.insert(result.begin(), '0'+num%10);
            num /= 10;
        }        
        if (isNegative) result.insert(result.begin(), '-');  // 如果是负数，添加负号
        return result;
    }
    vector<string> summaryRanges(vector<int>& nums) {

        int len = nums.size();
        if(len == 0) return vector<string>();
        if(len == 1) return vector<string>{intToString(nums[0])};

        vector<pair<int,int>> ans;
        int left = 0;
        int right = 1;
        // nums[left,right-1]: the current satisfied interval
        while(right < len){
            // checking if nums[right] satisfied
            // never use nums[right] - nums[right-1] > 1: as it will easily overflow:
            // anything - INT32_MIN will overflow
            if(nums[right] > 1 + nums[right-1]){
                ans.push_back({left, right-1});
                left = right;
                right = right +1;
            } else {
                right++;
            }
        }
        // append the last interval
        ans.push_back({left,right-1});

        vector<string> result;
        for(auto p: ans){
            if(p.first == p.second){
                result.push_back(intToString(nums[p.first]));
            }else{
                result.push_back(intToString(nums[p.first]) + "->" + intToString(nums[p.second]));
            }
        }
        return result;
    }
};

// official solution
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while(i < n){
            int low = i; 
            i++;
            while(i < n && nums[i] == nums[i-1]+1) {
                i++;
            }
            int high = i-1; // nums[low,...,high] satisfied
            string temp = to_string(nums[low]);
            if(low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }

        return ret;
    }
};