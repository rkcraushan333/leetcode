//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>>res(n,vector<int>(m,0));
	    vector<vector<bool>>vis(n,vector<bool>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]) {
	              vis[i][j] =1;
	              q.push({{i,j},0});}
	        }
	    }
	    int dx[] = {-1,1,0,0};
	    int dy[] = {0,0,-1,1};
	    while(!q.empty()){
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int r = x+dx[i],c = y+dy[i];
	            if(r<0||c<0||r>n-1||c>m-1||vis[r][c]) continue;
	            vis[r][c] = 1;
	            res[r][c] = d+1;
	            q.push({{r,c},d+1});
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends