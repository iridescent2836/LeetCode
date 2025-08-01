'''
time: O(n)
'''
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = 0
        max_palindromic_word_count = 0
        max_palindromic_word = ""
        
        records = Counter(words)

         # First, handle words like "cc" which are palindromic.
        # If such a word appears an odd number of times, it can be placed in the center of the palindrome.
        # Only one such center word is allowed, so we select the one with the highest count.
        for record in records:
            reverse = record[::-1]
            if reverse == record and records[record] % 2 == 1 and records[record] > max_palindromic_word_count:
                max_palindromic_word_count = records[record]
                max_palindromic_word = record
        
        if max_palindromic_word_count > 0:
            count += 2 * max_palindromic_word_count
            records[max_palindromic_word] = 0


        # Process the remaining words
        for record in records:
            reverse = record[::-1]
            # For other palindromic words like "cc", if the count is even, 
            # we can pair them up and place symmetrically in the palindrome.
            if reverse == record:
                count += records[record] // 2 * 4
                records[record] = 0

            # Normal situations for non-palindromic word pairs like "ab" and "ba"
            elif reverse in records:
                count += min(records[reverse], records[record])*4
                records[reverse] = 0
                records[record] = 0
            
        return count
    
# optimized version
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = 0
        center_used = False
        records = Counter(words)

        for word in records:
            rev = word[::-1]

            if word == rev:
                # 每两个可以放在两边
                pair = records[word] // 2
                count += pair * 4
                records[word] -= pair * 2

                # 如果还有一个剩下的，可以作为中心使用（仅一次）
                if records[word] > 0 and not center_used:
                    count += 2
                    center_used = True

            elif rev in records:
                pair = min(records[word], records[rev])
                count += pair * 4
                records[word] -= pair
                records[rev] -= pair

        return count

