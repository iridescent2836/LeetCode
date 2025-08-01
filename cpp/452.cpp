#include "header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if(len <= 1)
            return len;

        sort(points.begin(), points.end(), [] (vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        // greedy;
        int arrow_num = 1;
        int target_range_end = points[0][1];
        int x = points[0][0];
        for(int i = 1; i < len; i++) {
            if(points[i][0] <= target_range_end){
                target_range_end = min(points[i][1], target_range_end);
            }
            else{
                arrow_num++;
                target_range_end = points[i][1];
            }

        }
        return arrow_num;
    }
};

int main() {
    Solution s;

    vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}