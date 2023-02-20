class Solution {
public:
    int dp1[2502][2502];
    int f1(vector<int>&v,int l=-1,int i=0){
        if(i==v.size()) return 0;
        int &k = dp1[i][l+1];
        if(k!=-1) return k;
        int res = 0;
        res = max(res,f1(v,l,i+1));
        if(l==-1||v[l]<v[i]) res = max(res,1+f1(v,i,i+1));
        return k = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp1,-1,sizeof(dp1));
        return f1(nums);
    }
};