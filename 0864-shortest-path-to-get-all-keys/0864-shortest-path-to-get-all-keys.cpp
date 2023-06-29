struct keys{
    int row,col,dis,mask;
};
class Solution {
public:
    int n,m, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    int shortestPathAllKeys(vector<string>& grid) 
    {
        n = grid.size(); m = grid[0].size();
        int si,sj,nk=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@') 
                {
                    si = i;
                    sj = j;
                }
                if(grid[i][j]>='a') nk++;
            }
        }
        int vis[n][m][1<<nk];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<(1<<nk);k++) vis[i][j][k] = 0;
            }
        }
        queue<keys>q;
        q.push({si,sj,0,0});
        vis[si][sj][0] = 1;
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            int x = t.row,y = t.col;
            int d = t.dis;
            int msk = t.mask;
            // cout<<msk<<endl;
            // cout<<x<<" "<<y<<" "<<d<<" "<<msk<<endl;
            if(msk==(1<<nk)-1)
            {
                return d;
            }
            for(int i=0;i<4;i++)
            {
                int r = x+dx[i], c = y+dy[i],ms=msk;
                if(r<0||c<0||r>=n||c>=m||grid[r][c]=='#'||vis[r][c][ms]) continue;
                if(grid[r][c]>='a')
                {
                    ms |= 1<<(grid[r][c]-'a');
                    if(vis[r][c][ms]==1)
                    {
                        continue;
                    }
                    vis[r][c][ms] = 1;
                    q.push({r,c,d+1,ms});
                }
                else if(grid[r][c]>='A')
                {
                    if(msk&(1<<(grid[r][c]-'A')))
                    {
                        vis[r][c][msk] = 1;
                        q.push({r,c,d+1,msk});
                    }
                    else 
                    {
                        continue;
                    }
                }
                else 
                {
                    vis[r][c][msk] = 1;
                    q.push({r,c,d+1,msk});
                }
            }
        }
        return -1;
    }
};