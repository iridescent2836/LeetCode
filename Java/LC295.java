import java.util.PriorityQueue;
import java.util.Set;

public class LC295 {
    class MedianFinder {
        private PriorityQueue<Integer> maxHeap;  // 最大堆，存储较小的一半
        private PriorityQueue<Integer> minHeap;  // 最小堆，存储较大的一半


        public MedianFinder() {
            maxHeap = new PriorityQueue<>((a, b) -> b - a);  // 最大堆
            minHeap = new PriorityQueue<>((a, b) -> a - b);  // 最小堆
        }
        
        public void addNum(int num) {
            // 先加入最大堆
            maxHeap.offer(num);
            
            // 确保最大堆的顶部元素小于等于最小堆的顶部元素
            if (!maxHeap.isEmpty() && !minHeap.isEmpty() && 
                maxHeap.peek() > minHeap.peek()) {
                minHeap.offer(maxHeap.poll());
            }
            
            // 平衡两个堆的大小
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.offer(maxHeap.poll());
            }
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.offer(minHeap.poll());
            }
            
        }
        
        public double findMedian() {
            if(maxHeap.size() > minHeap.size()) return maxHeap.peek();
            else return (maxHeap.peek()+minHeap.peek()) / 2.0;
        }
    }
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder obj = new MedianFinder();
     * obj.addNum(num);
     * double param_2 = obj.findMedian();
     */  
}
