#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
    std::vector<int> heap;
    // 根节点索引为 0
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[idx] < heap[parent]) {
                std::swap(heap[idx], heap[parent]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int idx) {
        int size = heap.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != idx) {
                std::swap(heap[idx], heap[smallest]);
                idx = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin() const {
        if (heap.empty()) throw std::out_of_range("Heap is empty");
        return heap[0];
    }

    int extractMin() {
        if (heap.empty()) throw std::out_of_range("Heap is empty");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return minVal;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

// Example usage
int main() {
    MinHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(0);
    std::cout << "Min: " << h.getMin() << std::endl;
    std::cout << "Extracted Min: " << h.extractMin() << std::endl;
    std::cout << "Min after extraction: " << h.getMin() << std::endl;
    return 0;
}
