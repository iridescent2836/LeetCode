# 例子

假设有序数组：

```
[1, 2, 4, 4, 4, 5, 7]
```

目标找“4”的范围：

* `lower_bound(4)` → 第一个“4”的位置，是“4”的**开始边界（下界）**
* `upper_bound(4)` → 第一个大于“4”的位置（即“5”），是“4”的**结束边界（上界）**

区间 `[lower_bound, upper_bound)` 就是所有等于 4 的元素。



# 1. 基本介绍

这两个函数都属于 `<algorithm>` 头文件中的**二分查找算法**，适用于**有序区间**，作用是帮助快速定位元素的位置，时间复杂度是 O(log n)。

---

# 2. 函数原型

```cpp
template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value);
```

* `first`, `last`：定义查找的区间 `[first, last)`，必须是升序排序的区间。
* `value`：要查找的目标值。

---

# 3. 返回值含义

| 函数名           | 返回的是指向什么位置的迭代器                         |
| ------------- | -------------------------------------- |
| `lower_bound` | 返回第一个**不小于**（≥）`value`的元素位置（即最左侧的“下界”） |
| `upper_bound` | 返回第一个**大于**（>）`value`的元素位置（即最右侧的“上界”）  |

---

# 4. 举例说明

假设有序数组：

```cpp
std::vector<int> v = {1, 2, 4, 4, 4, 5, 7};
```

* `lower_bound(v.begin(), v.end(), 4)` 会返回指向第一个 `4` 的迭代器，即 `v[2]`。
* `upper_bound(v.begin(), v.end(), 4)` 会返回指向第一个大于 `4` 的元素的迭代器，即 `v[5]`，也就是元素 `5`。

---

# 5. 代码示例

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 4, 5, 7};

    auto lb = std::lower_bound(v.begin(), v.end(), 4);
    auto ub = std::upper_bound(v.begin(), v.end(), 4);

    std::cout << "Lower bound at index: " << (lb - v.begin()) << ", value: " << *lb << "\n";
    std::cout << "Upper bound at index: " << (ub - v.begin()) << ", value: " << *ub << "\n";

    // 统计元素4的个数
    int count = ub - lb;
    std::cout << "Count of 4: " << count << "\n";

    return 0;
}
```

输出：

```
Lower bound at index: 2, value: 4
Upper bound at index: 5, value: 5
Count of 4: 3
```

---

# 6. 使用场景

* **查找元素是否存在**：如果 `lower_bound` 返回的位置的值等于目标值，则元素存在。
* **统计重复元素个数**：使用 `upper_bound - lower_bound`。
* **插入位置定位**：`lower_bound` 返回的位置是保持有序插入的位置。

---

# 7. 区别总结

| 名称            | 返回值含义           | 包含等于的比较？ | 常用场景        |
| ------------- | --------------- | -------- | ----------- |
| `lower_bound` | 第一个 ≥ value 的位置 | 是        | 查找/插入位置     |
| `upper_bound` | 第一个 > value 的位置 | 否        | 统计元素个数、范围上界 |

---

# 8. 底层实现（简述）

两者都是基于**二分查找**实现：

* `lower_bound` 查找第一个不小于 `value` 的元素。
* `upper_bound` 查找第一个大于 `value` 的元素。

大致步骤：

* 设定搜索区间 `[first, last)`。
* 计算中间位置 `mid`。
* 比较 `*mid` 与 `value`：

  * 对于 `lower_bound`：

    * 如果 `*mid < value`，移动左边界到 `mid + 1`。
    * 否则，移动右边界到 `mid`。
  * 对于 `upper_bound`：

    * 如果 `*mid <= value`，移动左边界到 `mid + 1`。
    * 否则，移动右边界到 `mid`。
* 重复直到区间为空，返回左边界迭代器。

---

# 9. 总结

* `lower_bound` 找到“左边界”（第一个不小于目标值的元素）。
* `upper_bound` 找到“右边界”（第一个严格大于目标值的元素）。
* 它们共同帮助高效定位元素，支持快速插入、查找和计数。

---

如果你需要，我可以帮你写带自定义比较函数的版本，或者演示怎么用它们在实际项目中查找插入点。
