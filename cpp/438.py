# time O(len(s) * len(p))
# naive method

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        letter_count = [0] * 26
        for ch in p:
            letter_count[ord(ch) - ord('a')] += 1
        
        len_sub = len(p)

        ans = []
        for i in range(len(s)-len_sub+1):
            letter_count_tmp = [0] * 26
            for j in range(len_sub):
                idx = ord(s[i+j])-ord('a')
                letter_count_tmp[idx] += 1
                if letter_count_tmp[idx] > letter_count[idx]:
                    break
            else:
                ans.append(i)
        
        return ans


# I am a genius
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        
        letter_count = [0] * 26
        for ch in p:
            letter_count[ord(ch) - ord('a')] += 1
        
        len_sub = len(p)

        ans = []
        # initialize the sliding window.
        letter_count_window = [0] * 26
        flg = False
        for i in range(len_sub):
            letter_count_window[ord(s[i]) - ord('a')] += 1
        # check the initial window
        for i in range(26):
            if letter_count_window[i] != letter_count[i]:
                break
        else:
            flg = True
            ans.append(0)
            
        for i in range(1, len(s) - len_sub + 1):
            out = i-1
            new = i + len_sub - 10
            letter_count_window[ord(s[out]) - ord('a')]-=1
            letter_count_window[ord(s[new]) - ord('a')]+=1
            
            if s[out] == s[new] and flg:
                ans.append(i)
            elif s[out] != s[new] and flg:
                flg = False
            elif s[out] == s[new] and not flg:
                continue
            else:
                if letter_count_window == letter_count:
                    flg = True
                    ans.append(i)
        return ans

