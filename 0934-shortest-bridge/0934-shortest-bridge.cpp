class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void f(int i,int j,int n,vector<vector<int>>&v){
        if(i<0||j<0||i>=n||j>=n||(v[i][j]!=1)) return;
        v[i][j] = 2;
        for(int idx=0;idx<4;idx++){
            f(i+dx[idx],j+dy[idx],n,v);
        }
    }
    int shortestBridge(vector<vector<int>>&v) {
        int n=v.size();
        bool b = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    f(i,j,n,v);
                    b = 1;
                    break;
                }
            }
            if(b) break;
        }
        bool vis[n][n];
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==2) {q.push({{i,j},0});vis[i][j]=1;}
                else vis[i][j] = 0;
            }
        }
        while(q.size()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = r+dx[i],y = c+dy[i];
                if(x<0||y<0||x>=n||y>=n||vis[x][y]) continue;
                if(v[x][y]==1) return d;
                q.push({{x,y},d+1});
                vis[x][y] = 1;
            }
        }
        return 0;
    }
};