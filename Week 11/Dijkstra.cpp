#include <iostream>
#include <vector>
using namespace std;

#define V 5
#define INF 50000

int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printDistances(int dist[]) {
    cout << "Current Distances: ";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    cout << "Start Dijkstra from Vertex " << src + 1 << endl;
    cout << "-----------------------------------" << endl;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = true;

        cout << "\nStep " << count + 1 << endl;
        cout << "Select Vertex: " << u + 1 << endl;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && 
                dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {

                cout << "Update distance of Vertex " << v + 1;
                cout << " from " << dist[v];
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                cout << " to " << dist[v] << endl;
            }
        }

        printDistances(dist);
    }

    cout << "\n===== Final Shortest Distances =====" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i + 1 
             << " Distance = " << dist[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, 0, 9, 1},
        {5, 0, 2, 0, 0},
        {0, 2, 0, 6, 0},
        {9, 0, 6, 0, 2},
        {1, 0, 0, 2, 0}
    };

    dijkstra(graph, 0); 

    return 0;
}
