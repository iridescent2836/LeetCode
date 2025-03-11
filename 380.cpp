#include "header.h"



class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> table;


public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        // already exist
        if(table.count(val)) return false;

        int idx = nums.size();
        nums.emplace_back(val);
        table[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if(!table.count(val)) return false;
        
        int idx = table[val];
        int last = nums.back();
        nums[idx] = last;
        table[last] = idx;
        nums.pop_back();
        table.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIdx = rand()%nums.size();
        return nums[randIdx];
    }
};