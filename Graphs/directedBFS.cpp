#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, vector<vector<int>> &adj){

    //vector to store BFS traversal result
    vector<int> bfsResult;

    //queue for BFS
    queue<int> q;

    //To keep track of visited nodes
    vector<bool> visited(n, false);

    //BFS starts from node 0
    q.push(0);
    visited[0]=true;

    //BFS traversal
    while(!q.empty()){
        int node=q.front();
        q.pop();

        // Add the current node to the result
        bfsResult.push_back(node);

        //Traverse through the neighbors
        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=true;
            }
        }

    }
    return bfsResult;
}

int main(){
    int n=8; //Number of vertices
    vector<vector<int>> adj ={{1,2,3},{4,7},{5},{6},{},{},{},{}}; //Adjacency List

    vector<int> result =bfs(n,adj);

//output of BFS traversal
    for (int node:result){
        cout << node << "";
    }
}