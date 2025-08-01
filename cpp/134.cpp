#include "header.h"

// brute way
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for(int begin = 0; begin < len; begin++){
            int currGas = gas[begin];
            bool isfinished = true;
            for(int i = 1; i <= len; i++){
                int idx = (begin + i - 1) % len;
                currGas -= cost[idx];
                if(currGas < 0){
                    isfinished = false;
                    break;
                }
                idx = (idx + 1) % len;
                currGas += gas[idx];
            }
            if(isfinished) return begin;
        }
        return -1;
    }
};

// use the feature that there will be only one answer
// the the starting position must be after the minimum left gas
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int minLeftGas = INT32_MAX;
        int begin = 0;
        int leftGas = 0;
        for(int i = 0; i < len; i++){
            leftGas += gas[i] - cost[i];
            if(leftGas < minLeftGas){
                minLeftGas = leftGas;
                begin = (i+1)%len;
            }
        }
        return leftGas >= 0 ? begin : -1;
    }
};

