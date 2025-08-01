#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int prim(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    // minEdge[i] 存储的是当前未被选入最小生成树的节点 i 到已在生成树中的节点的最短边权值
    vector<int> minEdge(n, INT_MAX); 
    minEdge[0] = 0;

    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        // 找未访问节点中 minEdge 最小的
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalWeight += minEdge[u];

        // 更新邻接边的最小权值
        //  minEdge[v] 存储的是当前未被选入最小生成树的节点 v 到已在生成树中的节点的最短边权值

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

void testPrim() {
    vector<vector<int>> graph = {
        {0, 2, INT_MAX, 6, INT_MAX},
        {2, 0, 3, 8, 5},
        {INT_MAX, 3, 0, INT_MAX, 7},
        {6, 8, INT_MAX, 0, 9},
        {INT_MAX, 5, 7, 9, 0}
    };

    cout << "Prim最小生成树权值和: " << prim(graph) << endl; // 应该输出16
}


typedef pair<int, int> PII; // {权值, 点编号}

int primHeap(int n, const vector<vector<PII>>& adj) {
    vector<bool> visited(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    pq.push({0, 0}); // 从0号点开始
    int totalWeight = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true; // 选入最小生成树
        totalWeight += weight;

        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}

void testPrimHeap() {
    int n = 5;
    vector<vector<PII>> adj(n);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}, {4, 9}};
    adj[4] = {{1, 5}, {2, 7}, {3, 9}};

    cout << "堆优化 Prim 最小生成树权值和: " << primHeap(n, adj) << endl; // 输出 16
}

int main() {
    testPrim();
    return 0;
}