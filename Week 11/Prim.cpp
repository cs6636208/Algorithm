#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

void Prim(int V, vector<vector<pair<int,int>>> &adj, int src)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, src});
    key[src] = 0;

    int step = 1;
    int totalWeight = 0;

    cout << "Start Prim at vertex " << src + 1 << "\n\n";

    while (!pq.empty())
    {
        int u = pq.top().second;   
    	int weight = pq.top().first;
    	pq.pop();                 

    	if (inMST[u] == true)
        	continue;              

    	inMST[u] = true;           
    	totalWeight += weight;  

        if (parent[u] != -1)
        {
            cout << "Step " << step++
                 << ": Select edge (" << parent[u] + 1
                 << " - " << u + 1
                 << ") weight = " << weight << "\n";
        }

        for (int j = 0; j < adj[u].size(); j++)
    	{
        	int v = adj[u][j].first;  
        	int w = adj[u][j].second;  

        	if (inMST[v] == false && w < key[v])
        	{
            	key[v] = w;            
            	parent[v] = u;      
            	pq.push({w, v});       
        	}
    	}
    }

    cout << "\nTotal weight of MST = " << totalWeight << endl;
}

int main()
{
    int V = 6;
    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 3);
    addEdge(0, 4, 6);
    addEdge(1, 2, 5);
    addEdge(1, 4, 6);
    addEdge(2, 3, 9);
    addEdge(2, 5, 3);
    addEdge(4, 5, 2);
    addEdge(5, 3, 7);

    Prim(V, adj, 0); 

    return 0;
}
