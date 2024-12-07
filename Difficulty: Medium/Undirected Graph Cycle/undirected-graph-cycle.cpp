//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //bool isCycle(vector<vector<int>>& adj) {
      bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
        visited[node] = true;  // Mark the current node as visited
        
        // Visit all the neighbors of the current node
        for (int neighbor : adj[node]) {
            // If the neighbor is not visited, perform DFS recursively
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, node)) {
                    return true;  // Cycle detected
                }
            }
            // If the neighbor is visited and not the parent, a cycle exists
            else if (neighbor != parent) {
                return true;  // Cycle detected
            }
        }
        return false;  // No cycle found from this node
    }

    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);

        // Perform DFS from every unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1)) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;
      
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends