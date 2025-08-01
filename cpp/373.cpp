#include "header.h"

// detailed introduction of the solution prease refer to leetcode official document
// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/solutions/ this link is helpful as well
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // help comparing 2 combinations
        auto cmp = [&nums1, &nums2](const pair<int,int> & a, const pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < min(k,m);i++){
            pq.emplace(i,0);
        }
        while(k-->0 && !pq.empty()){
            auto [x,y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if(y+1<n){
                pq.emplace(x,y+1);
            }
        }
        return ans;
    }
};

// binary search
// clever clever methods
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        // count the number of pairs (nums1[i], nums2[j]) that satisfies nums1[i]+nums2[j] <= target. 
        // clever clever design of the function `count`
        auto count = [&](int target){
            long long cnt = 0;
            int start = 0;
            int end = n-1;
            // the pairs(nums1[start],nums2[0,...,end]) that satisfies the requirement. 
            while(start < m && end >= 0){
                if(nums1[start] + nums2[end] > target) {
                    end--;
                } else {
                    cnt += end+1;
                    start++;
                }
            }
            return cnt;
        };

        // use binary search to find the number `pairSum` that there are k pairs(nums1[i], nums2[j]) that
        // satisfies nums1[i] + nums2[j] <= pairSum
        int left = nums1[0]+nums2[0];
        int right = nums1.back() + nums2.back();
        int pairSum = right;
        while(left <= right) {
            int mid = left + ((right - left) >> 1); // clever to accelerate the calculation of (left + right)/2
            if (count(mid) < k) {
                left = mid + 1;
            } else {
                pairSum = mid;
                right = mid - 1;
            }
        }

        vector<vector<int>> ans;
        int pos = n - 1;

        // find the pair whose sum is smaller than pairSum
        for(int i = 0; i < m; i++) {
            while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum) {
                pos--;
            }
            // k > 0: to make sure there are at most k pairs
            for(int j = 0; j <= pos && k > 0; j++,k--){
                ans.push_back({nums1[i], nums2[j]});
            }
        }

        // find the pair whose sum is equal to pairSum
        pos = n - 1;
        for(int i = 0; i < m && k > 0; i++) {
            int start1 = i;
            // count the dup nums1
            while(i < m - 1 && nums1[i] == nums1[i+1]) {
                i++;
            }
            // skip the pair whose dum is bigger than pairSum
            while(pos >= 0 && nums1[i] + nums2[pos] > pairSum) {
                pos--;
            }
            int start2 = pos;
            // count the dup nums2
            while(pos > 0 && nums2[pos] == nums2[pos - 1]) {
                pos--;
            }
            // check if equal (because we just skipped the bigger pairs, 
            // there exists the posibility that the sum of pair is
            // smaller than pairSum)
            if(nums1[i] + nums2[pos] != pairSum) continue;

            // count is the number of duplicate pairs whose sum is equal to pairSum
            // use min(k,...) to make sure there are no more than k numbers
            int count = (int) min((long) k, (long) (i-start1+1) * (start2 - pos + 1));
            for(int j = 0; j < count && k > 0; j++,k--) {
                ans.push_back({nums1[i], nums2[pos]}); // why push the same pair? because they are duplicate. 
            }
        }
        return ans;
    }
};