#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V; // Number of vertices
    int E; // Number of edges
    vector<Edge> edges;

public:
    Graph(int vertices, int edges) : V(vertices), E(edges) {}

    // Function to add an edge with weight to the graph
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Bellman-Ford algorithm
    void bellmanFord(int source) {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;

        // Relax all edges |V| - 1 times
        for (int i = 0; i < V - 1; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                cout << "Graph contains negative weight cycle.\n";
                return;
            }
        }

        // Print the shortest distances
        cout << "Shortest distances from source " << source << " \n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices and 8 edges
    Graph graph(5, 8);

    // Add edges with weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 1);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 3);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, -7); // Negative weight cycle
    graph.addEdge(4, 0, 6); 

    // Run Bellman-Ford algorithm with source vertex 0
    graph.bellmanFord(0);

    return 0;
}
