#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void helper(vector<int>& vec, int left, int right) {
    if(left >= right) return;

    int pivotIdx = left;
    int pivot = vec[pivotIdx];

    for(int i = right; i > pivotIdx;) {
        if(vec[i] > pivot) i--;
        else {
            vec[pivotIdx] = vec[i];
            pivotIdx++;
            vec[i] = vec[pivotIdx];
        }
    }

    vec[pivotIdx] = pivot;

    helper(vec, left, pivotIdx-1);
    helper(vec, pivotIdx+1, right);
}

void qsort(vector<int>& vec) {
    helper(vec, 0, vec.size() - 1);
}


// 打印数组
void printVec(const vector<int>& vec) {
    for (int v : vec) cout << v << " ";
    cout << endl;
}

// 检查是否已排序
bool isSorted(const vector<int>& vec) {
    return is_sorted(vec.begin(), vec.end());
}

// 单个测试
void runTest(vector<int> vec, const string& name) {
    cout << "测试用例: " << name << endl;
    cout << "排序前: ";
    printVec(vec);
    qsort(vec);
    cout << "排序后: ";
    printVec(vec);
    cout << (isSorted(vec) ? "✅ 排序正确\n" : "❌ 排序错误\n") << endl;
}


int main() {
    runTest({}, "空数组");
    runTest({5}, "单元素");
    runTest({1, 2, 3, 4, 5}, "已排序数组");
    runTest({5, 4, 3, 2, 1}, "逆序数组");
    runTest({3, 1, 2, 3, 3, 0, 4}, "含重复元素");
    runTest({10, -1, 7, 0, 5, 2, 2}, "包含负数");
    runTest({100, 50, 25, 75, 0, -50, -100}, "正负交错");
}
