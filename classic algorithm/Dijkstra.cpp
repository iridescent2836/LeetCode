#include "header.h"

const int INF = INT_MAX;

typedef pair<int, int> PII; // first: 距离, second: 节点编号

vector<int> dijkstra(int n, vector<vector<PII>>& graph, int start){
    vector<int> dist(n, INF);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w]: graph[u]){
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// 测试函数
int main() {
    int n = 5; // 点数
    vector<vector<PII>> graph(n);

    // 添加边：graph[u].push_back({v, w});
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    int start = 0;
    vector<int> dist = dijkstra(n, graph, start);

    cout << "从节点 " << start << " 出发的最短距离为：" << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) cout << "节点 " << i << "：无法到达" << endl;
        else cout << "节点 " << i << "：" << dist[i] << endl;
    }

    return 0;
}