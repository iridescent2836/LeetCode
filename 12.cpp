#include "header.h"

class Solution {
public:
    void transfer(string& ans, int num,  char I, char V, char X){
        if(num > 0){
            switch (num)
            {
            case 9:
                ans.push_back(I);
                ans.push_back(X);
                break;
            case 4:
                ans.push_back(I);
                ans.push_back(V);
                break;
            default:
                int numOfV = num/5;
                int numOfI = num%5;
                for(int i = 0; i < numOfV ; i++){
                    ans.push_back(V);
                }
                for(int i = 0; i < numOfI; i++){
                    ans.push_back(I);
                }
                break;
            }
        }
    }

    string intToRoman(int num) {
        string ans;
        
        if(num >= 1000){
            int numOfM = num/1000;
            for(int i = 0; i < numOfM; i++){
                ans.push_back('M');
            }
        }
        int hundreds = num%1000/100;
        transfer(ans,hundreds,'C','D','M');
        int doubleDigits = num%100/10;
        transfer(ans,doubleDigits,'X','L','C');
        int singleDigits = num%10;
        transfer(ans,singleDigits,'I','V','X');
        return ans;
    }
};

// we have another 2 clever mehtods. Please refer to leecode official answer

int main(){
    Solution s = Solution();
    string ans = s.intToRoman(58);
    cout << ans << endl;
    return 0;
}
