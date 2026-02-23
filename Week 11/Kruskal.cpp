#include <iostream>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

bool isCycle(int parent[], int u, int v) {
    int x = find(parent, u);
    int y = find(parent, v);

    if (x == y)
        return true;
    else
        return false;
}

void kruskal(Edge edges[], int V, int E) {

    for (int i = 0; i < E - 1; i = i + 1) {
        for (int j = i + 1; j < E; j = j + 1) {
            if (edges[i].w > edges[j].w) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int parent[100];

    for (int i = 1; i <= V; i = i + 1) {
        parent[i] = -1;
    }

    int edgeCount = 0;
    int mstWeight = 0;

    cout << "=== Kruskal Algorithm Step-by-Step ===\n";

    for (int i = 0; i < E; i = i + 1) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        cout << "\nConsider edge (" << u << ", " << v
             << ") weight = " << w << endl;

        if (isCycle(parent, u, v) == false) {

            cout << " -> No cycle, select this edge\n";

            unionSet(parent, u, v);

            mstWeight = mstWeight + w;
            edgeCount = edgeCount + 1;

            cout << "    Parent array: ";
            for (int k = 1; k <= V; k = k + 1) {
                cout << parent[k] << " ";
            }
            cout << endl;
        }
        else {
            cout << " -> Cycle detected, skip\n";
        }

        if (edgeCount == V - 1) {
            break;
        }
    }

    cout << "\n=== Result ===\n";
    cout << "Total weight of MST = " << mstWeight << endl;
}

int main() {

    int V = 6;
    int E = 8;

    Edge edges[8] = {
        {5, 6, 2},
        {1, 2, 3},
        {3, 6, 3},
        {1, 5, 5},
        {2, 3, 5},
        {2, 5, 6},
        {4, 6, 7},
        {3, 4, 9}
    };

    kruskal(edges, V, E);

    return 0;
}
