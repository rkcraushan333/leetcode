//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n,m;
    set<vector<pair<int,int>>>s;
    void bfs(int sr,int sc,vector<vector<int>>&grid){
        int base1 = sr,base2 = sc;
        vector<pair<int,int>>v;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        grid[sr][sc] = 0;
        v.push_back({0,0});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int a=x+dx[i],b=y+dy[i];
                if(a<0||b<0||a>n-1||b>m-1||grid[a][b]==0) continue;
                grid[a][b] = 0;
                v.push_back({a-base1,b-base2});
                q.push({a,b});
            }
        }
        s.insert(v);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) bfs(i,j,grid);
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends