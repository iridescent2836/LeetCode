#include "header.h"

// stupid shit method
// time: O(n)
// space: O(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int size = rows*cols;
        vector<int> array(size);
        int idx = 0;
        for(auto line: matrix){
            for(auto num: line){
                array[idx++] = num;
            }
        }

        int left = 0, right = size-1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(array[mid] == target) return true;
            else if(array[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

// once search
// time: O(n)
// space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int size = rows*cols;

        int left = 0, right = size-1;
        while(left <= right){
            int mid = (left + right) >> 1;
            int row = mid / cols;
            int col = mid % cols;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

// twice search, fits for the situation when matrix is not rectangle
// time: O(n);
// space: O(1);
// 对c++库的高级用法，相当高级
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> & a){
            return b < a[0];
        });
        if(row == matrix.begin()) return false;
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};