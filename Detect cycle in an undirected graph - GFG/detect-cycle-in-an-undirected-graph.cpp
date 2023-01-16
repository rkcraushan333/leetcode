//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<bool>vis;
    bool dfs(vector<int>adj[],int i,int par){
        vis[i] = 1;
        for(auto &x:adj[i]){
            if(vis[x] && x!= par) return true;
            if(!vis[x]) {
                if(dfs(adj,x,i)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vis.resize(V);
        for(int i=0;i<V;i++){
          if(!vis[i])
               if(dfs(adj,i,-1)) 
                    return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends