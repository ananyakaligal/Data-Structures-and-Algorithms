#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// DFS to detect cycles
bool isCyclicDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;  // Mark as visited

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicDFS(neighbour, node, visited, adj)) return true; // Cycle found
        } else if (neighbour != parent) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle
}

// Detect cycles in the graph
string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited; // Track visited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, visited, adj)) return "Yes"; // Cycle found
        }
    }
    return "No"; // No cycle
}

// Main function with sample input
int main() {
    // Sample input: 5 nodes, 5 edges
    int n = 5, m = 5; 
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}, // Cycle here
        {2, 3},
        {3, 4}
    };

    string result = cycleDetection(edges, n, m);
    cout << "Cycle Detection Result: " << result << endl;

    return 0;
}
