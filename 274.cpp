#include "header.h"
#include <queue>
#include <unordered_map>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int h = 0;
        for(int i = citations.size() - 1; i >= 0; i--) {
            if(citations[i] > h) h++;
        }
        return h;
    }
};