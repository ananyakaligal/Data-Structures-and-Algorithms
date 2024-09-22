#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class Graph {
public:
    unordered_map<T, list<T>> adj;

    // Adding an edge to the graph
    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            // If it's undirected, create an edge from v to u
            adj[v].push_back(u);
        }
    }

    // Printing the adjacency list
    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;

    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    cout << "Enter the number of edges: " << endl;
    cin >> m;

    Graph <int>g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;

        // Creating a graph (undirected in this case)
        g.addEdge(u, v, 0); // Pass 0 for undirected graph
    }

    // Print the adjacency list
    g.printAdjList();

    return 0;
}
