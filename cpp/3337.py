# naive method: correct but time consuming
class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        MOD = 10**9+7
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        
        for _ in range(t):
            new_count = [0] * 26
            for i in range(26):
                for j in range(1, nums[i]+1):
                    idx = (i+j)%26
                    new_count[idx] = (new_count[idx] + count[i])%MOD
            count = new_count
            
        return sum(count) % MOD
        
# 快速幂 + 矩阵乘法
'''
f[i][j] represents the length of letter `j` after `i` times of substitutions

set c = nums[j]

f[i][j]=\sum_{k = j + 1}^{j + c}f[i - 1][k mod 26]

for detailed analysis, please refer to https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/solutions/2967037/ju-zhen-kuai-su-mi-you-hua-dppythonjavac-cd2j/?envType=daily-question&envId=2025-05-14
'''

MOD = 1_000_000_007

# a @ b
def mul(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    return [[sum(x * y for x, y in zip(row, col)) % MOD for col in zip(*b)] for row in a]

# a^n @ b
def pow_mul(a: List[List[int]], n: int, b: List[List[int]]) -> List[List[int]]:
    res = f0
    while n:
        # n is odd, a very efficient method. Instead of using the awful `n % 2 == 1`
        if n & 1:
            res = mul(a, res)
        a = mul(a, a)
        n >>= 1
    return res

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        SIZE = 26
        f0 = [[1] for _ in range(SIZE)]
        m = [[0] * SIZE for _ in range(SIZE)]
        
        for i, c in enumerate(nums):
            for j in range(i + 1, i + c + 1):
                m[i][j % SIZE] = 1
        mt = pow_mul(m, t, f0)
        
        ans = 0
        for ch, cnt in Counter(s).items():
            ans += mt[ord(ch) - ord('a')][0] * cnt
        
        return ans % MOD