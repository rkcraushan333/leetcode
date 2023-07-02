class Solution {
public:
    int n,m;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    bool dfs(vector<vector<int>>&v,vector<vector<bool>>&vis,int mid,int last,int i=0,int j=0)
    {
        if(i<0||j<0||i>=n||j>=m||vis[i][j]) return 0;
        if(abs(last-v[i][j])>mid) return 0;
        if(i==n-1&&j==m-1) return 1;
        vis[i][j] = 1;
        bool ans = 0;
        for(int x = 0;x<4;x++)
        {
            int a = i+dx[x],b = j+dy[x];
            ans |= dfs(v,vis,mid,v[i][j],a,b);
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        n = heights.size();
        m = heights[0].size();
        int s = -1,e = 1e9;
        while(e-s>1)
        {
            int mid = (s+e)>>1;
            vector<vector<bool>>vis(n,vector<bool>(m));
            if(dfs(heights,vis,mid,heights[0][0]))
            {
                e = mid;
            }
            else 
            {
                s = mid;
            }
        }
        return e;
    }
};