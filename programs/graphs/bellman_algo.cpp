#include<bits/stdc++.h>
using namespace std;
bool isNegativeWeightCycle(int n, vector<vector<int> >edges,int src){
        vector<int>Dist(n,1e8);
        Dist[src] = 0;
        for(int  i = 0;i < n-1;i++)
        {
            for(int j = 0;j < edges.size();j++)
            {
                int u  = edges[j][0];
                int v  = edges[j][1];
                int wt = edges[j][2];
                
                if(Dist[u] != 1e8 && Dist[u] + wt < Dist[v])
                {
                    Dist[v] = Dist[u] + wt;
                }
            }
        }
        for(int j = 0;j < edges.size();j++)
            {
                int u  = edges[j][0];
                int v  = edges[j][1];
                int wt = edges[j][2];
                if(Dist[u] + wt < Dist[v])
                {
                    return 1;
                }
            }
            return 0;
    }
int main(){
	int N, m;
        cin >> N >> m;
        vector<vector<int> > edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        int src;
        cin >> src;
        bool res = isNegativeWeightCycle(N, edges, src);
       if(res == true){
	cout<<"Negative cycle exist";
	}
	else{
		cout<<"No negative cycle";
	}
        cout << "\n";
        return 0;
}
