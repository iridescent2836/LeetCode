#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        parent[rx] = ry;
        return true;
    }
};

int kruskal(int n, const vector<Edge>& edges) {
    UnionFind uf(n);
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end());

    int totalWeight = 0;
    
    for (const Edge& e : sortedEdges) {
        if (uf.unite(e.u, e.v)) {
            totalWeight += e.weight;
        }
    }
    return totalWeight;
}

void testKruskal() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };
    int n = 5;

    cout << "Kruskal最小生成树权值和: " << kruskal(n, edges) << endl; // 应该输出16
}
