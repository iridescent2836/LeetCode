package ClassicAlgorithm;

// reference: https://www.bilibili.com/video/BV1V8DmYxEPV/?spm_id_from=333.1387.favlist.content.click&vd_source=95e8460b422bb7a24129e80ee6a2d2ad
public class FastModularExponentiation {
    // 计算 (base^exponent) % mod
    public static long fastPowMod(long base, long exponent, long mod) {
        if (mod == 1) return 0;
        long result = 1;
        base = base % mod;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent >>= 1;
        }
        return result;
    }

    public static long fastPow(long base, long exponent) {
        long result = 1;
        
        while(exponent > 0) {
            if((exponent & 1) == 1) {
                result = result * base;
            }
            base = base * base;
            exponent >>= 1;
        }

        return result;
    }


    public static void main(String[] args) {
        long base = 2, exponent = 10, mod = 1000;
        long result = fastPowMod(base, exponent, mod);
        System.out.println("快速幂取模结果: " + result); // 应输出 24
    }
}
