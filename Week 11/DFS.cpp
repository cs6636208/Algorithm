#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V + 1, false);
    vector<int> result;
    stack<int> st;

    st.push(start);
    visited[start] = true;
    result.push_back(start);

    cout << "Start at vertex: " << start << endl;
    cout << "Push " << start << " into stack\n\n";

    while (!st.empty()) {
        int current = st.top();
        cout << "Current vertex: " << current << endl;

        bool foundUnvisited = false;

        for (int i = 0; i < adj[current].size(); i++) {
            int neighbor = adj[current][i];

            if (!visited[neighbor]) {
                cout << "Found unvisited neighbor: " << neighbor << endl;
                st.push(neighbor);
                visited[neighbor] = true;
                result.push_back(neighbor);

                cout << "Push " << neighbor << " into stack\n\n";
                foundUnvisited = true;
                break;
            }
        }

        if (!foundUnvisited) {
            cout << "No unvisited neighbor for " << current << endl;
            cout << "Pop " << current << " from stack\n\n";
            st.pop();
        }
    }

    cout << "===== DFS Traversal Result =====" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V + 1);

    adj[1] = {2, 3};
    adj[2] = {1, 4};
    adj[3] = {1, 4, 5};
    adj[4] = {2, 3, 5, 6};
    adj[5] = {3, 4};
    adj[6] = {4};

    DFS(1, adj, V);

    return 0;
}
