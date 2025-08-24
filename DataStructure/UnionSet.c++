#include <vector>
#include <iostream>


// 并查集类
class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank; // 只是作为union的参考，是对树的高度的粗略近似，并不需要严格维护

public:
    // 构造函数，初始化 n 个元素
    DisjointSet(int n) : parent(n), rank(n, 0) {
        // 他们的双亲就是自己
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // 查找根节点，带路径压缩
    int find(int x) {
        // 根节点判断依据：根节点的双亲节点是他自己，即根节点满足 parent[root] == root
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合，按秩合并
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // 判断两个元素是否属于同一个集合
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    DisjointSet ds(5);

    ds.unite(0, 1);
    ds.unite(1, 2);

    std::cout << "0 and 2 connected? " << (ds.connected(0, 2) ? "Yes" : "No") << std::endl;
    std::cout << "3 and 4 connected? " << (ds.connected(3, 4) ? "Yes" : "No") << std::endl;

    ds.unite(3, 4);
    std::cout << "3 and 4 connected after unite? " << (ds.connected(3, 4) ? "Yes" : "No") << std::endl;

    ds.unite(2, 4);
    std::cout << "0 and 4 connected after unite? " << (ds.connected(0, 4) ? "Yes" : "No") << std::endl;

    return 0;
}