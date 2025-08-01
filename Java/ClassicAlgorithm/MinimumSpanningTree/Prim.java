package ClassicAlgorithm.MinimumSpanningTree;

import java.util.Arrays;

public class Prim {
    // Prim算法，返回最小生成树的权值和
    public static int prim(int[][] graph) {
        int n = graph.length;              // 顶点个数
        boolean[] visited = new boolean[n]; // 标记顶点是否已加入最小生成树
        int[] minEdge = new int[n];         // 记录每个顶点到已选顶点集合的最小边权
        Arrays.fill(minEdge, Integer.MAX_VALUE); // 初始化所有边权为无穷大
        minEdge[0] = 0;                    // 从顶点0开始，权值设为0，保证它首先被选中

        int res = 0;                      // 最小生成树权值和

        for (int i = 0; i < n; i++) {
            int u = -1;                   // 选择未访问的顶点中 minEdge 权值最小的顶点
            for (int v = 0; v < n; v++) {
                if (!visited[v] && (u == -1 || minEdge[v] < minEdge[u])) {
                    u = v;
                }
            }

            visited[u] = true;            // 将顶点u加入最小生成树集合
            res += minEdge[u];            // 累加边权

            // 更新 minEdge 数组：对每个未访问的顶点v，若通过u到v的边权更小，则更新
            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v] != 0 && graph[u][v] < minEdge[v]) {
                    minEdge[v] = graph[u][v];
                }
            }
        }
        return res;                      // 返回最小生成树的权值和
    }

    public static void main(String[] args) {
        // 图的邻接矩阵表示，0表示无边
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };

        int mstWeight = prim(graph);     // 调用Prim算法
        System.out.println("Prim最小生成树权值和: " + mstWeight);
    }
}
