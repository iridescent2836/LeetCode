#include <iostream>
#include <vector>
#include <climits> // INT_MAX
using namespace std;

vector<vector<int>> floyd(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n));

    // 复制初始图距离
    for (int i = 0; i < n; i++) {
        dist[i] = graph[i];
    }

    // Floyd-Warshall 三重循环
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // dist[a][b] == INT_MAX 表示这两点之间无边链接
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main() {
    const int INF = INT_MAX;
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    vector<vector<int>> dist = floyd(graph);

    cout << "Floyd 最短路结果：" << endl;
    for (const auto& row : dist) {
        for (int d : row) {
            if (d == INF) cout << "INF ";
            else cout << d << " ";
        }
        cout << "\n";
    }

    return 0;
}
