// Minimum Spanning Tree
// ...greedly :=> kruskal's Algorithm ....DSU
class dsu
{
private:
    int n;
    vector<int>par,Size;
public:
    dsu(int n)
    {
        this->n = n;
        par.resize(n);
        Size.resize(n,1);
        for(int i=0;i<n;i++) par[i] = i;
    }
    int Find(int a)
    {
        return par[a] = (a==par[a])?a:Find(par[a]);
    }
    void Union(int a,int b)
    {
        if(Size[a]<Size[b]) swap(a,b);
        Size[a] += Size[b];
        par[b] = a;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) 
    {
        int n = p.size();
        dsu *st = new dsu(n);
        vector<vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int wt = abs(p[j][0]-p[i][0])+abs(p[j][1]-p[i][1]);
                adj.push_back({wt,i,j});
            }
        }
        sort(adj.begin(),adj.end());
        int mst = 0;
        for(int i=0;i<adj.size();i++)
        {
            int a = st->Find(adj[i][1]);
            int b = st->Find(adj[i][2]);
            if(a!=b)
            {
                mst += adj[i][0];
                st->Union(a,b);
            }
        }
        delete st;
        return mst;
    }
};