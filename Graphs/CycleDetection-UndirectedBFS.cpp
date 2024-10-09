#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

// BFS to detect cycles
bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>>& adj) {
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]) {
            // Cycle detected if visited and not parent
            if(visited[neighbour] && neighbour != parent[front]) {
                return true;
            }
            // Mark as visited and enqueue
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

// Detect cycles in the graph
string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(isCyclicBFS(i, visited, adj)) return "Yes"; // Cycle found
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
        {2, 0},
        {2, 3},
        {3, 4}
    };

    string result = cycleDetection(edges, n, m);
    cout << "Cycle Detection Result: " << result << endl;

    return 0;
}
