import heapq
import collections
'''
clever method. Just push, and store the pos info inside.
Then ignore the number that are out of range. 
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = [(-nums[i], i) for i in range(k)]

        n = len(nums)

        heapq.heapify(q)

        ans = [-q[0][0]]
        for i in range(k,n):
            heapq.heappush(q, (-nums[i], i))
            while(q[0][1] <= i-k):
                heapq.heappop(q)
            ans.append(-q[0][0])
        
        return ans
    
'''
If nums[i] <= nums[j] and i < j. Then when i is in the window, j must alse be.
and nums[i] will never be the maximum number in the window. Hence, we can remove
it from the window permanent 

So, we use a queue to store the index that has not been removed. The indices in
the queue are stored in increasing order, and the values in the array nums cor-
responding to these indices are strictly decreasing. Also, we need to remove the 
indices that is out side of the window. 


the left most element in the window should be the maximum element int he window. 
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        
        q = collections.deque()
        # initializing
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            
        ans = [nums[q[0]]]
        
        for i in range(k, n):
            # remove the element that are on the left
            # of nums[i] and smaller or equal than nums[i]
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            
            # remove the element that is out of range. 
            while q[0] <= i-k:
                q.popleft()
                
            # the left most element should be the maximum element. 
            ans.append(nums[q[0]])
            
        return ans
        