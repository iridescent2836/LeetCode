#include "header.h"
// ????? i don't fully understand this method
class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r)
            return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)return quickselect(nums, l, j, k);
        else return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};


// use max heap
class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int heapSize) {
        // check it's children
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        int largest = i;
        if(leftChild < heapSize && nums[leftChild] > nums[largest])
            largest = leftChild;
        

        if(rightChild < heapSize && nums[rightChild] > nums[largest])
            largest=rightChild;
        
        if(largest!=i){
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapSize);
        }
    }


    void buildMaxHeap(vector<int>& nums, int heapSize){
        // from the 1st none leaf node
        // for a full binary tree, the node of index i
        // its parent is (i-1)/2

        // for the last leaf, nums[heapSize-1], its parent is
        // nums[(heapSize-1 -1)/2] == nums[heapSize/2-1]
        for(int i = heapSize/2-1; i >=0; i--){
            maxHeapify(nums, i, heapSize);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        int heapSize = nums.size();
        int len = heapSize;
        buildMaxHeap(nums, heapSize);
        for(int i = len-1; i >= len-k+1;--i){
            swap(nums[0], nums[i]);
            heapSize--;
            maxHeapify(nums,0,heapSize);
        }
        return nums[0];
    }
};