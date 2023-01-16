//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    void dfs(vector<vector<char>>&mat,int sr,int sc){
        int n = mat.size(),m = mat[0].size();
        if(sr<0||sc<0||sr>n-1||sc>m-1||(mat[sr][sc] !='O')) return;
        mat[sr][sc] = 'C';
        for(int i=0;i<4;i++) dfs(mat,sr+dx[i],sc+dy[i]);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0|| i==n-1||j==m-1) && mat[i][j]=='O') 
                    dfs(mat,i,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                else if(mat[i][j]=='C') mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends