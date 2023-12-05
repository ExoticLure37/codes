#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<iPair>> adjList;

public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void primMST();
};

Graph::Graph(int vertices) {
    V = vertices;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
}

void Graph::primMST() {
    priority_queue<iPair, vector<iPair>, greater<iPair>> minHeap;

    int src = 0; // Starting vertex

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inHeap(V, false);

    minHeap.push({0, src});
    key[src] = 0;

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();
        inHeap[u] = true;

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inHeap[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                minHeap.push({key[v], v});
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << "\n";
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();

    return 0;
}

