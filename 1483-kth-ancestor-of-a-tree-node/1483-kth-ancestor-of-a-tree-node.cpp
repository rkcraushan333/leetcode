class TreeAncestor {
public:
    vector<vector<int>>table;
    TreeAncestor(int n, vector<int>& parent) 
    {
        table.resize(21,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            table[0][i] = parent[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(table[i-1][j]==-1) table[i][j] = -1;
                else table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        int i = 0;
        while(k)
        {
            if(k&1)
            {
                node = table[i][node];
                if(node==-1) break;
            }
            i++;
            k>>=1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */