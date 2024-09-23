#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// DFS to detect cycles in a directed graph
bool isCyclicDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;       // Mark the node as visited
    dfsVisited[node] = true;    // Mark the node in the current DFS path

    // Explore all neighbors
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicDFS(neighbour, visited, dfsVisited, adj)) return true; // Cycle found
        } else if (dfsVisited[neighbour]) {
            return true; // Cycle detected if already visited in current DFS path
        }
    }

    dfsVisited[node] = false;   // Unmark the node for the current DFS path
    return false;               // No cycle detected
}

// Detect cycles in the directed graph
string cycleDetection(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list for the directed graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v); // Only directed edge u -> v
    }

    unordered_map<int, bool> visited;    // Track visited nodes
    unordered_map<int, bool> dfsVisited; // Track nodes in the current DFS path

    // Traverse each node to handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, visited, dfsVisited, adj)) return "Yes"; // Cycle found
        }
    }
    return "No"; // No cycle detected
}

// Main function
int main() {
    // Sample input: 4 nodes, 4 edges
    int n = 4;
    vector<pair<int, int>> edges = {
        {0, 1},   // Directed edge from 0 to 1
        {1, 2},   // Directed edge from 1 to 2
        {2, 3},   // Directed edge from 2 to 3
        {3, 1}    // Directed edge from 3 to 1 (this creates a cycle)
    };

    string result = cycleDetection(n, edges);
    cout << "Cycle Detection Result: " << result << endl;

    return 0;
}
