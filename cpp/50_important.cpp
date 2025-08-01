#include "header.h"

// time(logn)
// but things can get really bad.
// e.g. n = 1_000_000
// 第一个循环找到 i = 524288（约等于 2^19），只用了 19 次乘法。
// 第二个循环要补上 475712 次乘法！这变成了 近似 O(n)。
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == (double)0 || x == (double)1) return x;
        if(x == (double)-1) return n % 2 == 0 ? 1 : -1;

        long long abs_n;
        if(n != -2147483648)
            abs_n = n > 0 ? n : -n;
        else
            abs_n = 2147483648;
        double ret = x;
        long long i = 1;
        while(i <= abs_n){
            if((i << 1) > abs_n) break;
            ret = ret * ret;
            i = i << 1;
        }
        while(i < abs_n){
            ret = ret * x;
            i++;
        }

        if(n < 0) ret = 1.0/ret;
        return ret;

    }
};





/**
 * way faster
 * 
 * iteration
 * 
 * if n is even
 *  x^n = (x^2)^(n/2)
 * else
 *  x^n = x(x^2)^(n//2)   `//` refer to downward rounding division
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1;
        while (N) {
            if (N % 2 == 1) res *= x;
            x *= x;
            N /= 2;
        }
        return res;
    }

};



// recursive
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};


// tail recursive
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPowTail(x, N, 1.0);
    }

private:
    double fastPowTail(double x, long long n, double acc) {
        if (n == 0) return acc;
        if (n % 2 == 0)
            return fastPowTail(x * x, n / 2, acc);
        else
            return fastPowTail(x * x, n / 2, acc * x);
    }
};
    