#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;



int removeDuplicates(vector<int>& nums) {
    bool isDup = false;
    int len = nums.size();
    int lenAfterRemove = nums.size();

    if(len <= 2) {
        return len;
    }

    int temp = nums[0];
    for(int i = 1; i < len; i++) {
        // encounter the different character
        if(temp != nums[i]) {
            temp = nums[i];
            isDup = false;
        } else if(temp == nums[i] && isDup == false) { // encounter 1st same caracter
            isDup = true;
        } else if(temp == nums[i] && isDup == true) { // more than 2 different caracter
            lenAfterRemove--;
            nums.erase(nums.begin() + i);
            len--;
            i--;
        }
    }

    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return lenAfterRemove;
}


using namespace std;
int main() {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int len = removeDuplicates(nums);

    cout << len << endl;

    return 0;
}
