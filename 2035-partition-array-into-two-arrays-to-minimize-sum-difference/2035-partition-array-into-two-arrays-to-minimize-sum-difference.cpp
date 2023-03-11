class Solution {
public:
    vector<vector<int>>v1,v2;
    void f(vector<int>&nums,int i,int l,bool a,int cnt = 0,int sum =0){
        if(i==l){
            if(!a) v1[cnt].push_back(sum);
            else v2[cnt].push_back(sum);
            return;
        }
        f(nums,i+1,l,a,cnt,sum);
        f(nums,i+1,l,a,cnt+1,sum+nums[i]);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        v1.resize(n/2+1);
        v2.resize(n/2+1);
        f(nums,0,n/2,0);
        f(nums,n/2,n,1);
        int sum = accumulate(nums.begin(),nums.end(),0);
        int k = sum/2;
        for(auto &v:v2){
            sort(v.begin(),v.end());
        }
        int ans = INT_MIN;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<v1[i].size();j++){
                int curr = v1[i][j];
                int t = lower_bound(v2[n/2-i].begin(),v2[n/2-i].end(),k-curr)-v2[n/2-i].begin();
                if(t==v2[n/2-i].size()){
                    ans = max(ans,curr+v2[n/2-i][t-1]);
                }else{
                    if(v2[n/2-i][t]==k-curr)
                     ans = max(ans,curr+v2[n/2-i][t]);
                    if(t!=0){
                        ans = max(ans,curr+v2[n/2-i][t-1]);
                    }
                }
            }
        }
        return abs(sum - 2*ans); 
    }
};