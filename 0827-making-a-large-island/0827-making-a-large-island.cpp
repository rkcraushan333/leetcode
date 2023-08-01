class Solution {
public:
    vector<int>par,Size;
    int findSet(int u)
    {
        return par[u] = par[u]==u?u:findSet(par[u]);
    }
    void unionSet(int a,int b)
    {
        a = findSet(a);
        b = findSet(b);
        if(a!=b)
        {
            if(Size[a]<Size[b]) swap(a,b);
            par[b] = a;
            Size[a] += Size[b];
        }
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        par.resize(m*n);
        Size.resize(m*n,1);
        for(int i=0;i<m*n;i++) par[i] = i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    if(i>0) if(grid[i-1][j]) unionSet(i*m+j,(i-1)*m+j);
                    if(i<n-1) if(grid[i+1][j]) unionSet(i*m+j,(i+1)*m+j);
                    if(j>0) if(grid[i][j-1]) unionSet(i*m+j,i*m+(j-1));
                    if(j<m-1) if(grid[i][j+1]) unionSet(i*m+j,i*m+(j+1));
                }   
            }
        }
        int ans = 0;
        for(auto i:Size) ans = max(ans,i);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])
                {
                    set<int>st;
                    int curr = 1;
                    if(i>0) if(grid[i-1][j]) st.insert(findSet((i-1)*m+j));
                    if(i<n-1) if(grid[i+1][j]) st.insert(findSet((i+1)*m+j));
                    if(j>0) if(grid[i][j-1]) st.insert(findSet(i*m+(j-1)));
                    if(j<m-1) if(grid[i][j+1]) st.insert(findSet(i*m+(j+1)));
                    for(auto x:st) curr += Size[x];
                    ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};