#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;

    Edge() {}

    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    int V; 
    vector<Edge> edges; 
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    // Find set of an element i (uses path compression technique)
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }
    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
    void kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        cout << "Minimum Spanning Tree (MST) using Kruskal's algorithm:" << endl;
        int i = 0;

        while (i < edges.size()) {
            Edge nextEdge = edges[i++];

            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            if (x != y) {
                cout << "Edge " << nextEdge.src << " - " << nextEdge.dest << " Weight: " << nextEdge.weight << endl;
                Union(parent, rank, x, y);
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
