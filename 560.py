class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if len(nums) == 0:
            return 0
        left = 0
        right = 1
        
        sum_ = 0
        count = 0
        while right <= len(nums):
            if sum_ == k:
                count+=1
                
                right += 1
                
            elif sum_ > k:
                sum_ -= nums[left]
                left += 1
            else:
                
            
            right += 1
        return count