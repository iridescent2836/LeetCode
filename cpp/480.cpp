#include "header.h"


class DualHeap {
private:

    // 大根堆，维护较小的一半
    priority_queue<int> small;
    // 小根堆，维护较大的一半
    priority_queue<int, vector<int>, greater<int>> large;
    // 记录需要延迟删除的元素， key 为要删除的元素，value 为要删除的次数
    unordered_map<int, int> delayed;
    int k;

    // 维护 smallSize == largeSize || smallSize  == largeSize + 1
    int smallSize, largeSize;
    // 将堆顶可能的需要删除的元素全部删除
    template<typename T>
    void prune(T& heap) {
        while(!heap.empty()) {
            int num = heap.top();
            if(delayed.count(num)) {
                --delayed[num];
                if(!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            } else break;
        }
    }

    void makeBalance() {
        // small 比 large 多两个元素，
        // 说明上次 insert 加入的是 small 堆， small 堆顶的元素一定不是将要被删除的
        if(smallSize > largeSize+1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            // small 堆顶可能暴露出应该被删除的元素，于是处理，保证 small 堆顶元素是可用的
            prune(small);
        } 
        // large 比 small 多两个元素，
        // 说明上次 insert 加入的是 large 堆， large 堆顶的元素一定不是将要被删除的
        else if(smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            // large 堆顶可能暴露出应该被删除的元素，于是处理，保证 small 堆顶元素是可用的
            prune(large);
        }
    }



public:
    DualHeap(int _k): k(_k), smallSize(0), largeSize(0) {}

    void erase(int value){
        ++delayed[value];
        if(value <= small.top()) {
            -- smallSize;
            if(value == small.top()) prune(small);
        } else {
            -- largeSize;
            if(value == large.top()) prune(large);
        }
        makeBalance();
    }

    void insert(int value) {
        if(small.empty() || value <= small.top()) {
            small.push(value);
            ++ smallSize;
        } else {
            large.push(value);
            ++largeSize;
        }

        makeBalance();
    }

    double getMedian() {
        return k & 1 ? small.top() : ((double)small.top() + (double)large.top()) / 2.0;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> ans;
        if (k == 0) return ans;
        int len = nums.size();
        
        DualHeap dh(k);
        for(int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }

        ans.push_back(dh.getMedian());
        for(int i = k; i < len; i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i-k]);
            ans.push_back(dh.getMedian());
        }

        return ans;
    }
};



// insertion sort
// timeComplexity: O(n*k)
struct Node {
    int value;
    Node* next;
    Node(): value(0), next(nullptr) {}
    Node(int _value): value(_value), next(nullptr) {}
};

class Solution {
private:
    Node* head;
    int k;
public:
    void insertNode(Node* node) {
        Node* curr = head;
        while(curr->next != nullptr) {
            if(curr->next->value > node->value) {
                node->next = curr->next;
                curr->next = node;
                return;
            }
            curr = curr->next;
        }

        // node is the larget number
        curr->next = node;
        return;
    }

    bool deleteNode(int value) {
        Node* pre = head;
        while(pre->next != nullptr) {
            if(pre->next->value == value) {
                Node* toDelete = pre->next;
                pre->next = toDelete->next;
                delete toDelete;
                return true;
            }
            pre = pre->next;
        }
        return false;
    }

    double findMedian() {
        if(k&1) {
            int step = k / 2 + 1;
            Node* curr = head;
            for(int i = 0; i < step; i++) {
                curr = curr->next;
            }
            return curr->value;
        } else {
            int step = k / 2;
            Node* curr = head;

            for(int i = 0; i < step; i++) {
                curr = curr->next;
            }
            double add1, add2;
            add1 = curr->value;
            add2 = curr->next->value;
            return (add1 + add2) / 2.0;
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        head = new Node();
        this->k = k;

        int len = nums.size();
        for(int i = 0; i < k; i++) {
            Node* node = new Node(nums[i]);
            insertNode(node);
        }

        vector<double> ans;
        ans.push_back(findMedian());

        for(int i = k; i < len - k + 1; i++) {
            Node* node = new Node(nums[i]);
            insertNode(node);
            deleteNode(nums[i - k]);
            ans.push_back(findMedian());

        }
        return ans;
    }
};

/**
 * 和上面的逻辑一致，但是标准库会快非常多。
 * 因为vector是连续内存空间，连续内存天然更适合cache，
 * 标准库利用连续内存针对cache进行了很多优化，比如SIMD
 * 
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> ans;
        if (k == 0) return ans;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); ++i) {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1); // 当前要插入的元素
            // 在 [window.begin(), window.end() - 1) 范围内，查找第一个大于当前元素的位置（上界）
            auto const insertion_point = std::upper_bound(window.begin(), it, *it);
            // 将[insertation_point, it), [it, it+1)交换位置    
            // 实质就是将it插入到insertation_point之前
            std::rotate(insertion_point, it, it + 1);
            // 取排序后的中间元素（奇数取中位，偶数取中间两数平均）
            ans.push_back((static_cast<double>(window[k / 2]) + window[(k - 1) / 2]) / 2);
            // 删除出队的元素
            window.erase(std::find(window.begin(), window.end(), nums[i - k + 1]));      
        }
        return ans;
    }
};

/**
 * 相同的逻辑，但是用红黑树存储sliding window
 * time: O(nlogk)
 */
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> ans;
        if (k == 0) return ans;
        multiset<int> window(nums.begin(), nums.begin() + k);
        // next(it, k) it 之后的第 k 个迭代器
        auto mid = next(window.begin(), (k - 1) / 2);    
        for (int i = k; i <= nums.size(); ++i) {

            // k 值	  公式	                解释
            // 奇数	  *mid + *next(mid, 0)	next(mid, 0) 就是 mid 本身
            // 偶数	  *mid + *next(mid, 1)	取左中和右中平均值
            ans.push_back((static_cast<double>(*mid) + 
                            *next(mid, (k + 1) % 2)) / 2.0);
            if (i == nums.size()) break;
            
            window.insert(nums[i]);
            // 保证mid 始终指向中间的元素
            // 要新增的数在mid左边，mid应该--
            if (nums[i] < *mid) --mid; 
            // 要删除的数在mid左边，mid应该++
            if (nums[i - k] <= *mid) ++mid;
            // 删除最左边的元素（即当前窗口外的元素）
            // 注意用 lower_bound 而不是 find 
            // 是因为 multiset 允许重复，lower_bound 确保删除的是最左边那个值。
            window.erase(window.lower_bound(nums[i - k])); 
        }
        return ans;
    }
};