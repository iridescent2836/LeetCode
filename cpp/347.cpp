#include "header.h"

class Solution {
public:
    
    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        int len = nums.size();
        for(int i = 0; i < len; i++){
            cnt[nums[i]]++;
        }

        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);

        for(auto& [num, count]: cnt){
            // 维持最大的k个元素组成一个堆。
            if(q.size() == k) {
                if(q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }

            } else {
                q.emplace(num, count);
            }
        }

        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};