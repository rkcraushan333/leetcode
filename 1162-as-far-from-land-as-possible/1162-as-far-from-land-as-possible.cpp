class Solution {
public:
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) {q.push({{i,j},0});vis[i][j]=1;}
            }
        }
        if(q.size()==0||q.size()==n*n) return -1;
        int res = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            if(grid[x][y]==0) res = max(res,t);
            for(int i=0;i<4;i++){
                int a = x+dx[i],b=y+dy[i];
                if(a<0||b<0||a>=n||b>=n||vis[a][b]){
                    continue;
                }
                q.push({{a,b},t+1});
                vis[a][b] = 1;
            }
        }
        return res;
    }
};