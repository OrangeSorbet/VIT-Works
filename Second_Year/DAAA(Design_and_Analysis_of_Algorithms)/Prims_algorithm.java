import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Prims_algorithm {
    private final int V;
    private final List<List<Edge>> adj;

    static class Edge {
        int to, weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static class Node implements Comparable<Node> {
        int vertex, key;
        Node(int vertex, int key) {
            this.vertex = vertex;
            this.key = key;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.key, other.key);
        }
    }

    public Prims_algorithm(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v, int w) {
        adj.get(u).add(new Edge(v, w));
        adj.get(v).add(new Edge(u, w));
    }

    public void primMST() {
        int[] key = new int[V];
        int[] pi = new int[V];
        boolean[] inQ = new boolean[V];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(pi, -1);

        key[0] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0, 0));

        for (int i = 0; i < V; i++) inQ[i] = true;

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            int u = current.vertex;

            if (!inQ[u]) continue;
            inQ[u] = false;

            for (Edge edge : adj.get(u)) {
                int v = edge.to;
                if (inQ[v] && edge.weight < key[v]) {
                    key[v] = edge.weight;
                    pi[v] = u;
                    pq.add(new Node(v, key[v]));
                }
            }
        }

        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++) {
            if (pi[i] != -1) {
                System.out.println(pi[i] + " - " + i + "\t" + key[i]);
            }
        }
    }

    public static void main(String[] args) {
        Prims_algorithm graph = new Prims_algorithm(5);
        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 3, 6);
        graph.addEdge(1, 2, 3);
        graph.addEdge(1, 3, 8);
        graph.addEdge(1, 4, 5);
        graph.addEdge(2, 4, 7);
        graph.addEdge(3, 4, 9);

        graph.primMST();
    }
}