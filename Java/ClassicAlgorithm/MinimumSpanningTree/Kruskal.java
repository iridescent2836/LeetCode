package ClassicAlgorithm.MinimumSpanningTree;

import java.util.*;

public class Kruskal {
    static class Edge {
        int u, v, w;
        Edge(int u, int v, int w) {
            this.u = u; this.v = v; this.w = w;
        }
    }

    // Kruskal算法，返回最小生成树的权值和
    public static int kruskal(int[][] graph) {
        int n = graph.length;
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] != 0) {
                    edges.add(new Edge(i, j, graph[i][j]));
                }
            }
        }
        edges.sort(Comparator.comparingInt(e -> e.w));
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        int res = 0, count = 0;
        for (Edge e : edges) {
            int pu = find(parent, e.u), pv = find(parent, e.v);
            if (pu != pv) {
                parent[pu] = pv;
                res += e.w;
                count++;
                if (count == n - 1) break;
            }
        }
        return res;
    }

    private static int find(int[] parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };
        int mstWeight = kruskal(graph);
        System.out.println("Kruskal最小生成树权值和: " + mstWeight);
    }
}