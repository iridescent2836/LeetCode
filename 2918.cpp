#include "header.h"

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        long long sum1 = 0, sum2 = 0;
        long long count1 = 0, count2 = 0;

        int len = max(len1, len2);
        for(int i = 0; i < len; i++){
            if(i < len1){
                count1 += !nums1[i];
                sum1+=nums1[i];
            }
            if(i < len2){
                count2 += !nums2[i];
                sum2+=nums2[i];
            }
        }

        if(count1 == 0 && count2 == 0 && sum1 != sum2) return -1;
        else if(count1 == 0) {
            if(sum1 < sum2+count2) return -1;
        }else if(count2 == 0) {
            if(sum2 < sum1+count1) return -1;
        }  

        long long ret = max(sum1 + count1, sum2 + count2);
        return ret;
    }
};