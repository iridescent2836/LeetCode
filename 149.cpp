#include "header.h"

// brute
// time: O(n^3)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len <= 2) return len;
        int ans = INT32_MIN;
        // use i, j to determin a line
        for(int i = 0; i < len-1; i++){
            for(int j = i + 1; j < len; j++){
                int count = 2; 
                for(int k = 0; k < len; k++){
                    if(k == i || k == j) continue;
                    else if((points[k][0] - points[j][0]) * (points[i][1] - points[j][1]) ==
                       (points[k][1] - points[j][1]) * (points[i][0] - points[j][0])) ++count;
                }
                if(count > ans) ans = count;
            }
        }
        return ans;
    }
};

// time O(n^2 * logm)
// n is the number of points, m is the max difference of x and y
// for a selected point `i`, if there are `n` other points
// that have the same slope to `i`, 
// then there are n+1 points that are in the same line
// for detailed info and notices about calculate slope, 
// please refer to leetcode official solution. 


/**
 * we use several methods to potimize the algorithm:
 * 在点的总数量小于等于 2 的情况下，我们总可以用一条直线将所有点串联，此时我们直接返回点的总数量即可；
 * 当我们枚举到点 i 时，我们只需要考虑编号大于 i 的点到点 i 的斜率，因为如果直线同时经过编号小于点 i 的点 j，那么当我们枚举到 j 时就已经考虑过该直线了；
 * 当我们找到一条直线经过了图中超过半数的点时，我们即可以确定该直线即为经过最多点的直线；
 * 当我们枚举到点 i（假设编号从 0 开始）时，我们至多只能找到 n−i 个点共线。假设此前找到的共线的点的数量的最大值为 k，如果有 k≥n−i，那么此时我们即可停止枚举，因为不可能再找到更大的答案了。
 */
class Solution {
public:
    // important! goot way to calculate gcd
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int ans = INT32_MIN;
        for(int i = 0; i < n; i++){
            if(ans >= n-1 || ans > n/2) break;

            unordered_map<int,int>mp;
            for(int j = i+1; j < n; j++){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                // check if slope is 0 or 1, avoid /0 mistake
                if(x==0){
                    y=1;
                } else if(y == 0){
                    x = 1;
                } else {
                    if (y < 0) { // make sure slope y/x, y is pocitive, to make sure -1/2 and 1/-2 are stored the same
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    // to make the 2/4 or 1/2, which are the same slope, is stored in the same answer
                    x /= gcdXY;
                    y /= gcdXY;
                }
                // x,y \in [-10^4,10^4]
                // slope \in [-2*10^4, 2*10^4]
                // so my in [0, 2 * 10 ^ 4],
                // we can use val = my + (2 * 10 ^ 4 + 1) * mx to sote (mx, my)
                mp[y + x * 20001]++;
            }
            int maxn = 0;
            for(auto& [_, num] : mp){
                maxn = max(maxn, num+1);
            }
            ans = max(ans,maxn);

        }
        return ans;
    }
};