class TreeAncestor {
public:
    vector<vector<int>>bin;
    TreeAncestor(int n, vector<int>& parent) 
    {
        bin.resize(17,vector<int>(n));
        bin[0] = parent;
        for(int i=1;i<17;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(bin[i-1][j]==-1) bin[i][j] = -1;
                else {
                    bin[i][j] = bin[i-1][bin[i-1][j]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        int i=0;
        while(k)
        {
            if(k&1)
            {
                node = bin[i][node];
            }
            if(node==-1) return -1;
            i++;
            k >>= 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */