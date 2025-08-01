#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

using namespace std;

void quicksort(vector<int>& nums, int left, int right) {
    if (left >= right) return;

    // 1. 生成随机 pivot
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]); // 把 pivot 放到最后

    // 2. Lomuto partition
    int i = left - 1;
    // vec[left, i] 是 <= pivot的数
    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]); // 把 pivot 放回正确位置
    int mid = i + 1;

    // 3. 递归左右区间
    quicksort(nums, left, mid - 1);
    quicksort(nums, mid + 1, right);
}

void qsort(vector<int>& nums) {
    srand(time(0)); // 初始化随机种子（避免重复）
    quicksort(nums, 0, nums.size() - 1);
}
