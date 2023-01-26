class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        vector<int>dis(n,1e8);
        dis[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int>c(dis);
            for(auto e:v){
                c[e[1]] = min(c[e[1]],dis[e[0]]+e[2]);
            }
            dis = c;
        }
        if(dis[dst]==1e8) return -1;
        return dis[dst];
    }
};