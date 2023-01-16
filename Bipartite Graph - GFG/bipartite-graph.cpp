//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<bool>color;
    vector<bool>vis;
    bool dfs(int s,vector<int>adj[],int c){
        vis[s] = 1;
        color[s] = c;
        for(auto &i:adj[s]){
            if(vis[i]&&color[i]==c) return false;
            if(!vis[i])
                 if(!dfs(i,adj,!c)) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    color.resize(V);
	    vis.resize(V);
	    for(int i=0;i<V;i++){
	        if(!vis[i]) 
	           if(!dfs(i,adj,0)) return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends