// Using Dijkstra Algorithm
class Solution {
public:
    int dx[4] = {1,-1,0,0}; int dy[4] = {0,0,1,-1};
    int minimumEffortPath(vector<vector<int>>& v)
    {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            auto t = pq.top(); pq.pop();
            int d = t[0];
            int a = t[1],b = t[2];
            if(a==n-1&&b==m-1) return d;
            for(int i=0;i<4;i++)
            {
                int x = a + dx[i],y = b + dy[i];
                if(x<0||y<0||x>=n||y>=m) continue;
                int dd = max(d,abs(v[x][y]-v[a][b]));
                if(dis[x][y]>dd)
                {
                    dis[x][y] = dd;
                    pq.push({dd,x,y});
                }
            }
        }
        return 0;
    }
};