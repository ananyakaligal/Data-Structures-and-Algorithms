#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsDisconnected(int n, vector<vector<int>> &adj) {
    vector<int> bfsResult; // To store BFS traversal result
    vector<bool> visited(n, false); // To track visited nodes

    // Loop through all nodes
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // If the node is unvisited
            queue<int> q; // Queue for BFS
            q.push(i);
            visited[i] = true;

            // BFS traversal
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfsResult.push_back(node);

                // Traverse neighbors
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
    
    return bfsResult;
}

int main() {
    int n = 8; // Number of vertices
    vector<vector<int>> adj = {
        {1, 2}, // Edges from vertex 0
        {3},    // Edges from vertex 1
        {},     // Edges from vertex 2
        {4},    // Edges from vertex 3
        {},     // Edges from vertex 4
        {6},    // Edges from vertex 5
        {},     // Edges from vertex 6
        {}      // Edges from vertex 7
    };

    vector<int> result = bfsDisconnected(n, adj);

    // Output of BFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
