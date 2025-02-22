#include "header.h"
#include <map>
#include <unordered_map>
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //26个质数表
    int primeNum[26] = {5, 71, 31, 29, 2, 53, 59, 23, 11,
                        89, 79, 37, 41, 13, 7, 43, 97, 17,
                        19, 3, 47, 73, 61, 83, 67, 101};

    //every char is map to a prime
    unordered_map<char,int> AlphabettoPrime;
    for(int i = 0;i < 26;i++)
    {
        AlphabettoPrime[i+'a'] = primeNum[i];
    }

    //caculate the multiple of every string
    unordered_map<size_t,vector<string>> mp;
    for(auto s : strs)
    {
        size_t key = 1;
        int limit = s.size();
        for(int i = 0;i < limit;i++)
        {
            key *= AlphabettoPrime[s[i]];
        }
        mp[key].emplace_back(s);
    }
    vector<vector<string>> result;
    for(auto it = mp.begin();it != mp.end();it++)
    {
        result.push_back(it->second);
    }
    return result;
}









// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     //字母对应质数map
//     unordered_map<char, int> AlphtoPrime_Map;
//     //根据字母出现频率 优化了一下 高频字母对应小质数
//     int primeNum[26] = {5, 71, 31, 29, 2, 53, 59, 23, 11, 89, 79, 37, 41, 13, 7, 43, 97, 17, 19, 3, 47, 73, 61, 83, 67, 101};
//     for (int i = 0; i < 26; ++ i) {
//         AlphtoPrime_Map[i + 'a'] = primeNum[i];
//     }

//     //计算字符串对应的乘积key
//     unordered_map<unsigned int,vector<string>> mp;
//     unsigned int key;
//     for(string str:strs){
//         key = 1;
//         for(int index = 0 ; index < str.size() ; index++){
//             key *= AlphtoPrime_Map[str[index]];
//         }
//         mp[key].emplace_back(str);
//     }

//     //
//     vector<vector<string>> result;
//     for(auto it=mp.begin(); it !=mp.end() ; it++){
//       result.emplace_back(it->second);
//     }
//     return result;
// }
