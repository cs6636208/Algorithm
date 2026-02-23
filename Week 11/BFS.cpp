#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void BFS(const vector<vector<int>>& graph, int startVertex) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> result;
    queue<int> q;

    int step = 0;

    q.push(startVertex);
    visited[startVertex] = true;
    result.push_back(startVertex);

    cout << "Step\tCurrent\tQueue\n";
    cout << step++ << "\t-\t" << startVertex << endl;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << step << "\t" << current << "\t";

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];

            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                result.push_back(neighbor);
            }
        }

        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
        step++;
    }
    cout << endl;
    cout << "===== BFS Traversal Result =====" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1,7},        
        {0,2,7},      
        {1,3,8},      
        {2,4,5},      
        {3,5},        
        {3,4,6},      
        {5,7,8},      
        {0,1,6,8},    
        {2,6,7}       
    };

    BFS(graph, 8);
    return 0;
}
