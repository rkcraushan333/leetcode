class Solution {
public:
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    bool dfs(vector<vector<bool>>&vis,int i,int j,int r,int c,map<pair<int,int>,int>&mp,int m)
    {
        vis[i][j] = 1;
        if(mp[{i,j}]<=m) return 0;
        if(i==r-1) return 1;
        bool ans = 0;
        
        for(int x=0;x<4;x++)
        {
            int a = i+dx[x],b = j+dy[x];
            if(a<0||b<0||a>=r||b>=c||vis[a][b]) continue;
            ans |= dfs(vis,a,b,r,c,mp,m);
        }
        
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int s=-1,e=row*col;
        map<pair<int,int>,int>mp;
        for(int i=0;i<cells.size();i++)
        {
            mp[{cells[i][0]-1,cells[i][1]-1}] = i;
        }
        while(e-s>1)
        {
            int m = (s+e)>>1;
            vector<vector<bool>>vis(row,vector<bool>(col));
            bool b=0;
            for(int i=0;i<col;i++)
            {
                if(!vis[0][i])
                {
                    b = dfs(vis,0,i,row,col,mp,m);
                }
                if(b) break;
            }
            if(b)
            {
                s = m;
            }
            else
            {
                e = m;
            }
        }
        return s+1;
    }
};