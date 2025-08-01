#include "header.h"

/**
 * i am fucking genius
 * we make sure:
 * if there are odd number of elements
 *   leftSize == rightSize + 1
 * else
 *   leftSize == rightSize
 * 
 * space: O(n)
 * time:
 *     addNum: O(logn)
 *     findMid: O(1)
 * 
 * You can optimize it to satisfy
 *   abs(leftSize - rightSize) <= 1.
 * The logic should be more complex,
 * but there should be less operations.
 */

class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;

    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(leftMaxHeap.size() == rightMinHeap.size()){
            if(leftMaxHeap.empty()){
                leftMaxHeap.push(num);
            }
            else if(num > leftMaxHeap.top()){
                // add num into right
                rightMinHeap.push(num);
                // make sure the 2 heap satisfies my requirement
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
            } else {
                // add num into left, the requirement is already satisfied
                leftMaxHeap.push(num);
            }
        } else {
            if(rightMinHeap.empty()){
                int topVal = leftMaxHeap.top();
                leftMaxHeap.pop();
                leftMaxHeap.push(std::min(topVal, num));
                rightMinHeap.push(std::max(topVal, num));
            }
            else if(num < rightMinHeap.top()){
                // add num to left
                leftMaxHeap.push(num);
                // make sure the 2 heap satisfies my requirement
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            } else {
                // add num into right, the requirement is already satisfied
                rightMinHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size())
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        else 
            return leftMaxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */