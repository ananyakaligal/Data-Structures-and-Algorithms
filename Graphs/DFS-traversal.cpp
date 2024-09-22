#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<bool> &visited, const vector<vector<int>> &adj, vector<int> &dfsResult) {
    visited[node]=true;
    dfsResult.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited, adj, dfsResult);
        }
    }
}

vector<int> dfs(int n, vector<vector<int> & adj){
    vector<int> dfsResult; // To store DFS traversal result
    vector<bool> visited(n, false); // To track visited nodes

    //for both connected and disconnected graph
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            dfsUtil(i,visited,adj,dfsResult);
        }
    }

    //only for connected graph
    //dfsUtil(0, visited, adj, dfsResult);

    return dfsResult;
}

int main() {
    int n = 8; // Number of vertices
    vector<vector<int>> adj = {
        {1, 2}, // Edges from vertex 0
        {0, 3}, // Edges from vertex 1
        {0, 5}, // Edges from vertex 2
        {1, 4}, // Edges from vertex 3
        {3},    // Edges from vertex 4
        {},     // Edges from vertex 5
        {2},    // Edges from vertex 6
        {}      // Edges from vertex 7
    };

    vector<int> result = dfs(n, adj);

    // Output of DFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}