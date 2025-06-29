'''
The following algorithm is wrong, because 
it can't solve the example below. 
[[  1,  2,  3,  4,  5],
 [  6,  7,  8,  9, 10],
 [ 11, 12, 13, 14, 15],
 [ 16, 17, 18, 19, 20],
 [ 21, 22, 23, 24, 25]]
'''

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        
        left = 0
        right = cols-1
        target_col = 0
        while left <= right:
            mid = (left + right)//2
            if matrix[0][mid] == target:
                return True
            if matrix[0][mid] <= target:
                target_col = mid
                left = mid +1
            else:
                right = mid -1
        
        top = 0
        bottom = rows-1
        target_row = 0
        while top <= bottom:
            mid = (top + bottom)//2
            if matrix[mid][target_col] == target:
                return True
            if matrix[mid][target_col] <= target:
                target_row = mid
                top = mid+1
            else:
                bottom = mid -1
        if matrix[target_row][target_col] == target:
            return True
        
        top = 0
        bottom = rows-1
        target_row = 0
        while top <= bottom:
            mid = (top + bottom)//2
            if matrix[mid][0] == target:
                return True
            if matrix[mid][0] <= target:
                target_row = mid
                top = mid+1
            else:
                bottom = mid -1
            
        left = 0
        right = cols-1
        target_col = 0
        while left <= right:
            mid = (left + right)//2
            if matrix[0][mid] == target:
                return True
            if matrix[0][mid] <= target:
                target_col = mid
                left = mid+1
            else:
                right = mid -1
        

        if  matrix[target_row][target_col] == target:
            return True
        return False



class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == target:
                    return True
                
        return False
        

# binary search for each row. 
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        
        for i in range(rows):
            left = 0
            right = cols-1
            while left <= right:
                mid = (left + right)//2
                if matrix[i][mid] == target:
                    return True
                elif matrix[i][mid] < target:
                    left = mid +1
                else:
                    right = mid -1
        
        return False


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        x, y = 0, n - 1
        while x < m and y >= 0:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] > target:
                y -= 1
            else:
                x += 1
        return False
