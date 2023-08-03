//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector<pair<int,int>>adj[n];
        for(auto v:edges)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int>dis(n,1e9);
        dis[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(pq.size())
        {
            auto t = pq.top(); pq.pop();
            int d = t.first;
            int node = t.second;
            for(auto i:adj[node]){
                if(d+i.second<dis[i.first])
                {
                    dis[i.first] = d+i.second;
                    pq.push({d+i.second,i.first});
                }
            }
        }
        for(auto &i:dis) if(i==1e9) i = -1;
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends