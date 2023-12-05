#include <bits/stdc++.h>
using namespace std;
class Graph {
private:
    int V;
    list<int> *adj;
public:
    Graph(int v) {
        V = v;
        adj = new list<int>[v];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i])	
                DFSUtil(*i, visited);
        }
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (visited[*i])	
                cout<<"CYCLE";
break;
        }
    }
    void DFS(int v) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        DFSUtil(v, visited);
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);

    return 0;
}
