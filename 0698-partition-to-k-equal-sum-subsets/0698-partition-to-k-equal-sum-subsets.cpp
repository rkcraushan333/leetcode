class Solution {
public:
    int dp[1<<16][18];
    bool f(vector<int>&v,int s,int k,int curr=1,int mask=0)
    {
        if(curr==k) 
        {
            return true;
        }
        if(mask==(1<<v.size())-1) 
        {
            return false;
        }
        int &rkc = dp[mask][curr];
        if(rkc!=-1)
        {
            return rkc;
        }
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(mask&(1<<i))
            {
                ans += v[i];
            }
        }
        if(ans > s*curr) 
        {
            return rkc=false;
        }
        bool t = 0;
        if(ans == s*curr)
        {
            for(int i=0;i<v.size();i++)
            {
                if(mask&(1<<i)) continue;
                t |= f(v,s,k,curr+1,mask|(1<<i));
            }
        }
        else
        {
            for(int i=0;i<v.size();i++)
            {
                if(mask&(1<<i)) continue;
                t |= f(v,s,k,curr,mask|(1<<i));
            }
        }
        return rkc=t;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
        memset(dp,-1,sizeof(dp));
        return f(nums,sum/k,k);
    }
};