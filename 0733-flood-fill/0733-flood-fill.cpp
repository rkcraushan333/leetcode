class Solution {
public:
    int dx[4] = {0,0,1,-1}; int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>&v,int i,int j,int c,int pc)
    {
        if(i<0||j<0||i>=v.size()||j>=v[0].size()) return;
        if(v[i][j]==pc)
        {
            v[i][j] = c;
            for(int k=0;k<4;k++)
            {
                dfs(v,i+dx[k],j+dy[k],c,pc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int c) 
    {
        int n=v.size(),m=v[0].size();
        if(v[sr][sc]==c) return v;
        dfs(v,sr,sc,c,v[sr][sc]);
        return v;
    }
};