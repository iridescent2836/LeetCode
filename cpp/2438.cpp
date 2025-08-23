#include "header.h"


class Solution {
public:
    static constexpr long long mod = 1000000007;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(unsigned long long n, vector<vector<int>>& queries) {
        vector<long long> powers;
        for (int i = 0; i < 64; i++) {
            if (n & (1ULL << i)) powers.push_back(1ULL << i);
        }

        vector<long long> prefix(powers.size());
        prefix[0] = powers[0] % mod;
        for (size_t i = 1; i < powers.size(); i++) {
            prefix[i] = prefix[i-1] * powers[i] % mod;
        }

        vector<int> ans;  // 直接用 int
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long res = prefix[r];
            /*
            (a * b)mod c == ((a mod c) * (b mod c) )mod c
            (a / b)mod c != ((a mod c) / (b mod c) )mod c  
            (prefix[r] / prefix[l-1]) % mod == res * modpow(prefix[l-1], mod-2) % mod
            */
            if (l > 0) res = res * modpow(prefix[l-1], mod-2) % mod;
            ans.push_back((int)res); // 强转成 int
        }
        return ans;
    }

};
