#include "header.h"

// time: O(nlogn) + O(n) = O(nlogn);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<vector<int>> ret;
        vector<int> temp;
        for(auto interval: intervals){
            if(temp.size() == 0){
                temp = interval;
                continue;
            }
            
            // no overlapping
            if(interval[0] > temp[1]){
                ret.push_back(temp);
                temp = interval;
            }
            // overlap
            else{
                temp[1] = max(interval[1], temp[1]);
            }

        }

        ret.push_back(temp);
        return ret;
    }
};

// a more beautiful version
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
