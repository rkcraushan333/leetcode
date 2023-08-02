//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int shortestDistance(int n, int m, vector<vector<int>> v, int x, int y) 
    {
        if(v[0][0]==0) return -1;
        queue<vector<int>>q;
        q.push({0,0,0});
        v[0][0] = 0;
        while(q.size())
        {
            auto t = q.front(); q.pop();
            int r = t[0],c = t[1];
            int d = t[2];
            if(r==x&&c==y) return d;
            for(int i=0;i<4;i++)
            {
                int r1 = r+dx[i];
                int c1 = c+dy[i];
                if(r1<0||c1<0||r1>=n||c1>=m||v[r1][c1]==0) continue;
                q.push({r1,c1,d+1});
                v[r1][c1] = 0;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends