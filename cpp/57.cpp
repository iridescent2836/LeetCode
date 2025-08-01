#include "header.h"

class Solution {
public:
    // notice that this method only apply to the situation that 
    // there is no overlapping in the origional `intervals`
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        vector<vector<int>> ret;
        bool flg = true;
             
        for(const auto& interval: intervals){
            // overlap 
            if(!(interval[1] < newInterval[0] || interval[0] > newInterval[1])){
                if(flg){
                    ret.push_back(newInterval);
                    flg = false;
                }
                ret.back()[0] = min(interval[0], ret.back()[0]);
                ret.back()[1] = max(interval[1], ret.back()[1]);
            }
            // no overlapping and newInterval is on the rightside
            else if(interval[1] < newInterval[0]){
                    ret.push_back(interval);
            }
            // no overlapping and new interval is on the leftside
            else{
                if(flg){
                    ret.push_back(newInterval);
                    flg = false;
                }
                ret.push_back(interval);
            }
        }
        if(flg) {
            ret.push_back(newInterval);
            flg = false;
        }
        return ret;
    }
};