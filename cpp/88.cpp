#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copyOfNums1 = nums1;
        // access every element in nums1 and nums2
        int i1 = 0;
        int i2 = 0;
        int idx = 0;
        for(; i1 < m && i2 < n;) {
            // put the element in nums1 into copyOfNums1
            if(copyOfNums1[i1] < nums2[i2]) {
                nums1[idx] = copyOfNums1[i1];
                idx++;
                i1++;
            } else{
                // put the element in nums2 into copyOfNums1
                nums1[idx] = nums2[i2];
                idx++;
                i2++;
            }
        }
        // fill the remaining elements into nums1.
        for( ; i1 < m; i1++) {
            nums1[idx] = copyOfNums1[i1];
            idx++;
        }

        for( ; i2 < n; i2++) {
            nums1[idx] = nums2[i2];
            idx++;
        }
    }
};