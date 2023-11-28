#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;
    vector<vector<int>> reverseAdjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices), reverseAdjList(vertices) {}

    // Function to add a directed edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        reverseAdjList[dest].push_back(src); // Reverse the edge for the reversed graph
    }

    // DFS for the original graph
    void DFS(int vertex, vector<bool>& visited, stack<int>& s) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, s);
            }
        }

        s.push(vertex);
    }

    // DFS for the reversed graph
    void reverseDFS(int vertex, vector<bool>& visited, vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);

        for (int neighbor : reverseAdjList[vertex]) {
            if (!visited[neighbor]) {
                reverseDFS(neighbor, visited, component);
            }
        }
    }

    // Function to find strongly connected components
    void findStronglyConnectedComponents() {
        stack<int> s;
        vector<bool> visited(V, false);

        // Step 1: DFS on the original graph and fill the stack
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited, s);
            }
        }

        // Reset visited array
        fill(visited.begin(), visited.end(), false);

        // Step 2: DFS on the reversed graph using the stack
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                vector<int> component;
                reverseDFS(vertex, visited, component);

                // Print the strongly connected component
                cout << "Strongly Connected Component: ";
                for (int v : component) {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    // Create a graph with 7 vertices
    Graph graph(7);

    // Add directed edges
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 3);
    graph.addEdge(5, 6);

    // Find and print strongly connected components
    graph.findStronglyConnectedComponents();

    return 0;
}
