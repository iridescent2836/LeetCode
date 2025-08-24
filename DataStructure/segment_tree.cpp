#include <vector>
#include <climits>
#include <iostream>

using namespace std;


struct node {
    int data, lazy = 0;
};


// 根节点索引为 1
void build(const vector<int> data, vector<node>& tree, int root, int left, int right) {
    if(left == right) {
        tree[root].data = data[left];
        return;
    }

    // 等于 (left + right) / 2 向下取整
    // 防止 (left + right) 太大导致的数据溢出
    int mid = left + ((right - left) >> 1);
    // 是完全二叉树，左子节点为 2 * root, 右子节点为 2 * root + 1
    // 递归构造左子树
    int left_kid = root << 1;
    int right_kid = (root << 1) + 1;
    build(data, tree, left_kid , left, mid);
    // 递归构造右子树
    build(data, tree, right_kid, mid + 1, right);
    tree[root].data = max(tree[left_kid].data, tree[right_kid].data);
}

// 处理懒标记
void pushDown(vector<node> & tree, int root) {
    if(tree[root].lazy != 0) {
        int left = root << 1;
        int right = (root << 1) + 1;
        tree[left].data += tree[root].lazy;
        tree[left].lazy += tree[root].lazy;

        tree[right].data += tree[root].lazy;
        tree[right].lazy += tree[root].lazy;

        tree[root].lazy = 0;
    }
}

// 查询[left, right]区间的最大值
int query(vector<node>& tree, int root, int left, int right, int queryLeft, int queryRight) {
    if(queryRight < left || right < queryLeft) {
        return INT_MIN;
    }
    if (queryLeft <= left && right <= queryRight) {
        return tree[root].data;
    }

    int mid = left + ((right - left) >> 1);
    pushDown(tree, root); // 处理懒标记
    int leftMax = query(tree, root << 1, left, mid, queryLeft, queryRight); // 查询左子树
    int rightMax = query(tree, (root << 1) + 1, mid + 1, right, queryLeft, queryRight); // 查询右子树
    
    // 返回二者最大值
    // 为什么可以？因为没有交集的区间返回的都是 INT_MIN 会被过滤掉
    return max(leftMax, rightMax); 
}

void update(vector<node> & tree, int root, int left , int right, int idx, int value) {
    if (left == right) {
        tree[root].data = value;
        tree[root].lazy = 0;
        return;
    }
    int mid = left + ((right - left) >> 1);
    pushDown(tree, root);
    int left_kid = root << 1;
    int right_kid = left_kid + 1;
    if(idx <= mid) {
        update(tree, left_kid, left, mid, idx, value);
    } else {
        update(tree, right_kid, mid + 1, right, idx, value);
    }
    tree[root].data = max(tree[left_kid].data, tree[right_kid].data);
}

void updateRange(vector<node>& tree, int root, int left, int right, int update_left, int update_right, int value) {
    if (update_right < left || right < update_left) {
        return; // 区间无交集，直接返回
    }
    if (update_left <= left && right <= update_right) {
        tree[root].data += value; // 更新当前节点的值
        tree[root].lazy += value; // 设置懒标记
        return;
    }


    int mid = left + (right - left) / 2;
    pushDown(tree, root); // 处理懒标记

    int left_kid = root << 1;
    int right_kid = left_kid + 1;
    updateRange(tree, left_kid, left, mid, update_left, update_right, value); // 更新左子树
    updateRange(tree, right_kid, mid + 1, right, update_left, update_right, value); // 更新右子树
    tree[root].data = max(tree[left_kid].data, tree[right_kid].data); // 更新当前节
}


// ========== 测试代码 ==========
int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};  // 下标从 0 开始
    int n = data.size();
    vector<node> tree(4 * n);  // 线段树大小设为原数组的四倍

    // 构建线段树
    build(data, tree, 1, 0, n - 1);

    // 查询区间 [1, 4] 的最大值，应该是 9
    cout << "Initial max in range [1,4]: " << query(tree, 1, 0, n - 1, 1, 4) << endl;

    // 区间加值更新：将 [1, 3] 所有值加 3
    updateRange(tree, 1, 0, n - 1, 1, 3, 3);
    cout << "After adding 3 to range [1,3], max in [1,4]: " << query(tree, 1, 0, n - 1, 1, 4) << endl;

    // 单点更新：将 index 2 的值改为 100
    update(tree, 1, 0, n - 1, 2, 100);
    cout << "After setting index 2 to 100, max in [0,5]: " << query(tree, 1, 0, n - 1, 0, 5) << endl;

    return 0;
}