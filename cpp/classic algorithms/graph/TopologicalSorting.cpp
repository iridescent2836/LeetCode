#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 输入：有向无环图（DAG）顶点数 n，邻接表 graph
// 输出：拓扑排序序列，如果有环则返回空vector
vector<int> topologicalSort(int n, const vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    // 计算每个点的入度
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    // 入度为0的点入队
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        // 将可从 u 到达的点的入度都减 1
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // 如果排序节点数不等于顶点数，说明有环，返回空vector
    if ((int)order.size() != n) 
        return {};

    return order;
}

int main() {
    // 示例图，顶点0指向1和2，1指向3，2指向3
    int n = 4;
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {3};
    graph[3] = {};

    vector<int> order = topologicalSort(n, graph);

    if (order.empty()) {
        cout << "Graph has a cycle, no topological order." << endl;
    } else {
        cout << "Topological order: ";
        for (int v : order) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
