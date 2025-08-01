#include "header.h"

/**
 * 单调栈解决
 * 维护一个温度非严格单调递减的栈。
 * 当遇到比当前栈顶温度更高的天气的时候，将栈中温度更低的天气退出。
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len);
        stack<int> s;
        for(int i = 0; i < len; i++){
            
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int prevIndex = s.top();
                ans[prevIndex] = i-prevIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};