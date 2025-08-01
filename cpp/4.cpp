#include "header.h"

/**
 * simple way
 * time: O(len1 + len2)
 * space: O(len1 + len2)
 */
class SolutionSimple {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        

        vector<int> newNums(len1 + len2, 0);
        int i1 = 0, i2=0;
        while(i1 < len1 && i2 < len2){
            if(nums1[i1] < nums2[i2]){
                newNums[i1+i2] = nums1[i1];
                i1++;
            } else {
                newNums[i1+i2] = nums2[i2];
                i2++;
            }
        }
        
        while(i1 < len1){
            newNums[i1+i2] = nums1[i1];
            i1++;
        }
        while(i2 < len2){
            newNums[i1+i2] = nums2[i2];
            i2++;
        }


        int mid = (len1+len2)>>1;
        if((len1 + len2) % 2 == 0){
            return (newNums[mid] + newNums[mid-1]) / 2.0f;
        } else {
            return newNums[mid];
        }
    }
};

class Solution {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();

        // to make sure the size of nums1 is smaller than nums2;
        if(len1 > len2) return findMedianSortedArrays(nums2, nums1);

        int left = 0;
        int right = len1;
        // mid1 is the maximum of the `left group`
        // mid2 is the minimum of the `right group`
        int mid1 = 0, mid2 = 0;

        while(left <= right) {
            // the `left group` include nums1[0,...,i-1], nums2[0,...,j-1]
            // the `right group` include nums[i,...,len1-1], nums2[j,...,len2-2]
            int i = (left+right) >> 1;
            // to make sure if the total length(len1+len2) is odd, the left 
            //group(length of i+j) has one more element than the right group. 
            int j = ((len1 + len2 + 1) >> 1) - i;

            int nums1_i_minus_1 = (i == 0 ? INT32_MIN : nums1[i-1]);
            int nums1_i = (i == len1 ? INT32_MAX : nums1[i]);

            int nums2_j_minus_1 = (j == 0 ? INT32_MIN : nums2[j-1]);
            int nums2_j = (j == len2 ? INT32_MAX : nums2[j]);

            // I am always confused about the edge case in
            // binary search. 
            if(nums1_i_minus_1 <= nums2_j){
                mid1 = max(nums1_i_minus_1, nums2_j_minus_1);
                mid2 = min(nums1_i, nums2_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (len1 + len2) % 2 == 0 ? (mid1 + mid2) / 2.0 : mid1;
    }
};


int main(){
    vector<int> nums1{1,2};
    vector<int> nums2{3,4};

    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}