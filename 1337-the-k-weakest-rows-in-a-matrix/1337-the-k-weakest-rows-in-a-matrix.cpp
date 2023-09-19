class Solution {
public:
    int bin(vector<int>&a){
        int s = -1, e = a.size();
        while(e-s>1){
            int m = (s+e)/2;
            if(a[m]==0){
                e = m;
            }else
                s = m;
        }
        return s+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(i,bin(mat[i])));
        }
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b) ->
             bool{
                 if(a.second==b.second)
                     return a.first<b.first;
                 else
                     return a.second<b.second;
             }
            );
        vector<int>t;
        for(auto i=0;i<k;i++){
            t.push_back(v[i].first);
        }
        return t;
    }
};