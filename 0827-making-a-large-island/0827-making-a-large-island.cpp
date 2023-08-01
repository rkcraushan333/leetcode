class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<vector<pair<int,int>>>vis;
    void dfs(vector<vector<int>>&grid,int i,int j,int id,int &cnt)
    {
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||vis[i][j].second||grid[i][j]==0) return;
        vis[i][j] = {id,1};
        cnt++;
        for(int k=0;k<4;k++)
        {
            dfs(grid,i+dx[k],j+dy[k],id,cnt);
        }
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n,vector<pair<int,int>>(m));
        unordered_map<int,int>hash;
        int id = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j].second)
                {
                    int cnt = 0;
                    dfs(grid,i,j,id,cnt);
                    hash[id] = cnt;
                    id++;
                    ans = max(ans,cnt);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>ids;
                    if(i>0)
                    {
                        if(grid[i-1][j])
                        {
                            ids.insert(vis[i-1][j].first);
                        }
                    }
                    if(i<n-1)
                    {
                        if(grid[i+1][j])
                        {
                            ids.insert(vis[i+1][j].first);
                        }
                    }
                    if(j>0)
                    {
                        if(grid[i][j-1])
                        {
                            ids.insert(vis[i][j-1].first);
                        }
                    }
                    if(j<m-1)
                    {
                        if(grid[i][j+1])
                        {
                            ids.insert(vis[i][j+1].first);
                        }
                    }
                    int temps=1;
                    for(auto x:ids)
                    {
                        temps += hash[x];
                    }
                    ans = max(ans,temps);
                }
            }
        }
        return ans;
    }
};