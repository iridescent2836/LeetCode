import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Test {
    // Dijkstra's algorithm: returns shortest distances from source to all vertices
    public static int[] dijkstra(int[][] graph, int source, int end) {
        int n = graph.length;
        int[] dist = new int[n];
        int[] path = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        boolean[] visited = new boolean[n];
        dist[source] = 0;
        path[source] = -1;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));

        pq.offer(new int[] {source, 0});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0];
            if(visited[u]) continue;

            visited[u] = true;
            for(int v = 0; v < n; v++) {
                if (graph[u][v] > 0 && !visited[v]) {
                    int newDist = dist[u] + graph[u][v];
                    if (newDist < dist[v]) {
                        path[v] = u;
                        dist[v] = newDist;
                        pq.offer(new int[]{v, dist[v]});
                    }
                }
            }

        }

        List<Integer> pathToEnd = new ArrayList<>();
        int curr = end;
        while (curr != -1) {
            pathToEnd.add(curr);
            curr = path[curr];
        }
        Collections.reverse((pathToEnd));

        System.out.println(pathToEnd);

        // System.out.println(Arrays.toString(path));
        
        return dist;

    }

    public static void main(String[] args) {
        // 构造一个有向图的邻接矩阵，0表示无边
        int[][] graph = {
            {0, 2, 0, 1, 0},
            {0, 0, 3, 2, 0},
            {0, 0, 0, 0, 7},
            {0, 0, 4, 0, 3},
            {0, 0, 0, 0, 0}
        };
        int source = 0;
        int end = 4;
        int[] dist = dijkstra(graph, source, end);

        System.out.println("从节点 " + source + " 到各节点的最短距离：");
        for (int i = 0; i < dist.length; i++) {
            System.out.println("到节点 " + i + " 的距离: " + dist[i]);
        }
    }
}
