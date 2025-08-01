# similiar to bubble sort

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        while i >= 0:
            # move i to the tail
            if nums[i] == 0:
                curr = i 
                nxt = i+1
                while   nxt < len(nums) and nums[nxt]!=0:
                    nums[curr] = nums[nxt]
                    curr+=1
                    nxt+=1
                nums[nxt-1] = 0
            
            i-=1
            
# double pointers
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        ready = unready = 0
        while unready < len(nums):
            if nums[unready] != 0:
                nums[ready], nums[unready] = nums[unready], nums[ready]
                ready += 1
            unready += 1