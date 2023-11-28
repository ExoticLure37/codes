#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // Function to add a directed edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    // Recursive function for DFS
    void DFS(int vertex, vector<bool>& visited, stack<int>& s) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, s);
            }
        }

        // Push the current vertex to the stack after visiting all neighbors
        s.push(vertex);
    }

    // Function to perform topological sort
    void topologicalSort() {
        stack<int> s;
        vector<bool> visited(V, false);

        // Call DFS for each unvisited vertex
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited, s);
            }
        }

        // Print the contents of the stack (topological order)
        cout << "Topological Sort: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add directed edges
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    // Perform topological sort
    graph.topologicalSort();

    return 0;
}
