// using multisource BFS
class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int orangesRotting(vector<vector<int>>& v) 
    {
        int n = v.size(),m = v[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2) q.push({{i,j},0});
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int tm = t.second;
            ans = max(ans,tm);
            for(int i=0;i<4;i++)
            {
                int x = r+dx[i],y = c+dy[i];
                if(x<0||y<0||x>=n||y>=m) continue;
                if(v[x][y]==1)
                {
                    v[x][y] = 2;
                    q.push({{x,y},tm+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) if(v[i][j]==1) return -1;
        }
        return ans;
    }
};