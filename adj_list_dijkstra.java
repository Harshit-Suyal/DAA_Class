import java.util.*;

class adj_list_graph {
    class Edge {
        int dest;
        int weight;
        
        public Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }

    private LinkedList<Edge>[] adj;  

    public adj_list_graph(int v) {
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList<Edge>();
        }
    }

    public void addedge(int s, int d, int weight) {
        adj[s].add(new Edge(d, weight));  
        adj[d].add(new Edge(s, weight));  
    }

    public void dijkstra(int src) {
        int V = adj.length;
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE); 
        dist[src] = 0;  

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(u -> dist[u]));
        pq.add(src);

        while (!pq.isEmpty()) {
            int u = pq.poll();

            for (Edge edge : adj[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.add(v);
                }
            }
        }

        System.out.println("Shortest distances from source vertex " + src + ":");
        for (int i = 0; i < V; i++) {
            System.out.println("Vertex " + i + " : " + (dist[i] == Integer.MAX_VALUE ? "No path" : dist[i]));
        }
    }

    public void printgraph() {
        for (int i = 0; i < adj.length; i++) {
            System.out.print("Vertex " + i + ":");
            for (Edge edge : adj[i]) {
                System.out.print(" (" + edge.dest + ", " + edge.weight + ")");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of vertices and edges: ");
        int v = sc.nextInt();
        int e = sc.nextInt();

        adj_list_graph g = new adj_list_graph(v);

        System.out.println("Enter the edges (u v weight): ");
        for (int i = 0; i < e; i++) {
            int s = sc.nextInt();
            int d = sc.nextInt();
            int weight = sc.nextInt();
            g.addedge(s, d, weight);
            
        g.printgraph();

        System.out.println("Enter the source vertex for Dijkstra's algorithm: ");
        int src = sc.nextInt();

        g.dijkstra(src);
    }
}
}

