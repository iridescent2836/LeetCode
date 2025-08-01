#include "header.h"

// we use greedy
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq; // 大顶堆
        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({capital[i], profits[i]}); 
        }

        sort(arr.begin(), arr.end()); // 按captial从小到大排序
        for(int i = 0; i < k; i++){
            // 获得当前能够购买的所有项目的利润
            while(curr < n && arr[curr].first <= w){
                pq.push(arr[curr].second);
                curr++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            } else {
                break;
            }
        }
        return w;
    }
};