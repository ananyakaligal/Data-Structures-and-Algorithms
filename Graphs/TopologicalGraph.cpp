#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

// Helper function for DFS and topological sort
bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& inRecStack, stack<int>& sorted, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    inRecStack[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, inRecStack, sorted, adj)) return true; // Cycle detected
        } else if (inRecStack[neighbor]) return true; // Cycle found
    }

    inRecStack[node] = false;
    sorted.push(node); // Add node to stack after visiting neighbors
    return false;
}

// Topological sort and cycle detection
string topologicalSort(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (auto& edge : edges) adj[edge.first].push_back(edge.second);

    unordered_map<int, bool> visited, inRecStack;
    stack<int> sorted;

    // Traverse each node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, inRecStack, sorted, adj)) return "Cycle Detected";
        }
    }

    // Collect sorted nodes
    string topologicalOrder = "Topological Sort: ";
    while (!sorted.empty()) {
        topologicalOrder += to_string(sorted.top()) + " ";
        sorted.pop();
    }

    return topologicalOrder;
}

// Main function
int main() {
    int n = 4;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1} // Graph with a cycle
    };

    cout << topologicalSort(n, edges) << endl;
    return 0;
}
