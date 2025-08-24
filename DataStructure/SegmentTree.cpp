#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    struct Node {
        int maxValue = 0;
        int lazy = 0;
    };

    vector<Node> tree;
    int n;

    void build(const vector<int>& data, int root, int left, int right) {
        if (left == right) {
            tree[root].maxValue = data[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(data, root * 2, left, mid);
        build(data, root * 2 + 1, mid + 1, right);
        tree[root].maxValue = max(tree[root * 2].maxValue, tree[root * 2 + 1].maxValue);
    }

    void pushDown(int root) {
        if (tree[root].lazy != 0) {
            for (int child : {root * 2, root * 2 + 1}) {
                tree[child].maxValue += tree[root].lazy;
                tree[child].lazy += tree[root].lazy;
            }
            tree[root].lazy = 0;
        }
    }

    void updateRange(int root, int left, int right, int ul, int ur, int val) {
        if (ur < left || right < ul) return;
        if (ul <= left && right <= ur) {
            tree[root].maxValue += val;
            tree[root].lazy += val;
            return;
        }
        pushDown(root);
        int mid = left + (right - left) / 2;
        updateRange(root * 2, left, mid, ul, ur, val);
        updateRange(root * 2 + 1, mid + 1, right, ul, ur, val);
        tree[root].maxValue = max(tree[root * 2].maxValue, tree[root * 2 + 1].maxValue);
    }

    int query(int root, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return INT_MIN;
        if (ql <= left && right <= qr) return tree[root].maxValue;
        pushDown(root);
        int mid = left + (right - left) / 2;
        int lmax = query(root * 2, left, mid, ql, qr);
        int rmax = query(root * 2 + 1, mid + 1, right, ql, qr);
        return max(lmax, rmax);
    }

    void updatePoint(int root, int left, int right, int idx, int val) {
        if (left == right) {
            tree[root].maxValue = val;
            tree[root].lazy = 0;
            return;
        }
        pushDown(root);
        int mid = left + (right - left) / 2;
        if (idx <= mid)
            updatePoint(root * 2, left, mid, idx, val);
        else
            updatePoint(root * 2 + 1, mid + 1, right, idx, val);
        tree[root].maxValue = max(tree[root * 2].maxValue, tree[root * 2 + 1].maxValue);
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void updateRange(int left, int right, int val) {
        updateRange(1, 0, n - 1, left, right, val);
    }

    void updatePoint(int index, int val) {
        updatePoint(1, 0, n - 1, index, val);
    }

    int query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};


int main() {
    vector<int> data = {12, 3, 5, 7, 9, 11};
    SegmentTree st(data);

    cout << "Initial max in [0, 4]: " << st.query(0, 4) << endl;  // 12

    st.updateRange(1, 3, 3);
    cout << "After adding 3 to [1, 3], max in [1, 4]: " << st.query(1, 4) << endl;  // 10

    st.updatePoint(2, 100);
    cout << "After setting index 2 to 100, max in [0, 5]: " << st.query(0, 5) << endl;  // 100

    return 0;
}
