#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

// 方法1：仿函数（struct + operator()）推荐方式，功能强大，泛型兼容好
struct Compare1 {
    bool operator()(int a, int b) {
        return a > b;  // 小顶堆：值小的优先（默认是大顶堆）
    }
};

// 方法2：使用 lambda 表达式（C++11 及以后支持）
auto compare2 = [](int a, int b) {
    return a > b;  // 小顶堆
};

// 方法3：函数指针
bool compare3(int a, int b) {
    return a > b;  // 小顶堆
}

// 方法4：使用 greater<T> 和 less<T> 等标准比较器（无需自定义）
void standard_comparator_example() {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 小顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap;     // 大顶堆（默认）
}

int main() {
    // 使用方法1：仿函数
    priority_queue<int, vector<int>, Compare1> pq1;
    pq1.push(3); pq1.push(1); pq1.push(5);
    cout << "pq1 top (Compare1): " << pq1.top() << endl;

    // 使用方法2：lambda（注意类型很复杂）
    priority_queue<int, vector<int>, decltype(compare2)> pq2(compare2);
    pq2.push(3); pq2.push(1); pq2.push(5);
    cout << "pq2 top (lambda): " << pq2.top() << endl;

    // 使用方法3：函数指针
    priority_queue<int, vector<int>, bool(*)(int, int)> pq3(compare3);
    pq3.push(3); pq3.push(1); pq3.push(5);
    cout << "pq3 top (function pointer): " << pq3.top() << endl;

    // 使用方法4：标准比较器 greater（小顶堆）
    priority_queue<int, vector<int>, greater<int>> pq4;
    pq4.push(3); pq4.push(1); pq4.push(5);
    cout << "pq4 top (greater<>): " << pq4.top() << endl;

    // 使用方法5：默认大顶堆
    priority_queue<int, vector<int>> pq4;

    return 0;
}
