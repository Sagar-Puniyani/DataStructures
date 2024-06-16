#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

void bfs(int n, vector<vector<int>> &adj) {
    queue<int> q;
    vector<bool> visited(n, false); 

    
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; 

        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);


    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    bfs(n, adj);

    return 0;
}
