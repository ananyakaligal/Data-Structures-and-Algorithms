#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// DFS to detect cycles in directed graph
bool isCyclicDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& recStack, unordered_map<int, list<int>>& adj) {
    visited[node] = true;    // Mark visited
    recStack[node] = true;   // Mark recursion stack

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicDFS(neighbour, visited, recStack, adj)) return true; // Cycle found
        } 
        else if (recStack[neighbour]) {
            return true; // Cycle detected
        }
    }

    recStack[node] = false;  // Remove from recursion stack
    return false;            // No cycle
}

// Detect cycles in directed graph
string cycleDetectionDirected(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // Directed edge from u to v
    }

    unordered_map<int, bool> visited;   // Track visited nodes
    unordered_map<int, bool> recStack;  // Track recursion stack

    // Check for cycles
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, visited, recStack, adj)) return "Yes"; // Cycle found
        }
    }
    return "No"; // No cycle
}

// Main function with sample input
int main() {
    int n = 4, m = 4; 
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}  // Cycle here
    };

    string result = cycleDetectionDirected(edges, n, m);
    cout << "Cycle Detection Result: " << result << endl;

    return 0;
}
