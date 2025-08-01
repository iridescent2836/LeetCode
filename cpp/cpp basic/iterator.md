## next()
`next(it, k)` 在 C++ 中的功能是：返回一个迭代器，它是从 `it` 向后移动 `k` 步之后的位置。

是否等价于 `it + k`，**要看迭代器的类型**。

---

### ✅ **区别与使用场景：**

#### 1. **随机访问迭代器（如 `vector<int>::iterator`）**

* `next(it, k)` ≡ `it + k`，功能完全等价。
* 因为随机访问迭代器支持加法操作。

#### 2. **双向迭代器（如 `list<int>::iterator`、`set<int>::iterator`、`multiset<int>::iterator`）**

* `it + k` ❌ **不合法**，**编译错误**。
* `next(it, k)` ✅ 正确，可以使用。

#### 3. **前向迭代器（如 `forward_list<int>::iterator`）**

* 同样只能使用 `next(it, k)`。

---

### 🧠 **为什么使用 `next`？**

* **通用性更强**：`next` 是一个泛型函数，适用于各种迭代器类型（包括不能 `+k` 的）。
* **可读性强**：明确表达“向后移动 `k` 步”。

---

### 📌 示例：

```cpp
#include <iostream>
#include <set>
#include <iterator> // for std::next

int main() {
    std::multiset<int> ms = {1, 2, 2, 3, 4};

    auto it = ms.begin();
    std::advance(it, 2); // 等价于 next(ms.begin(), 2)，此时 it 指向第二个 2

    std::cout << *it << '\n'; // 输出：2

    auto it2 = std::next(ms.begin(), 3); // 更安全的写法
    std::cout << *it2 << '\n'; // 输出：3
}
```

---

### ✅ 总结：

* `next(it, k)` 是推荐的写法，适用于所有标准迭代器。
* `it + k` 只能用于支持随机访问的迭代器（如 vector、deque）。
* 在使用如 `set`、`multiset` 时应避免用 `it + k`，应使用 `next(it, k)`。
