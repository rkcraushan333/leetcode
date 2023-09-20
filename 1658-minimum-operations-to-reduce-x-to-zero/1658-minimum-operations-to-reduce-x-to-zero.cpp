// Deep Dive into it
class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        vector<int>suf(n);
        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            suf[i] = nums[i]+suf[i+1];
        reverse(suf.begin(),suf.end());
        int i=0,sm=0;
        for(i=0;i<n;i++)
        {
            if(sm+nums[i]>x) 
            {
                i--;
                break;
            }
            sm += nums[i];
        }
        if(i==n) 
        {
            if(sm==x) return n;
            if(sm<x) return -1;
        }
        int ans = INT_MAX;
        if(sm==x) 
        {
            ans = min(ans,i+1);
            sm -= nums[i];
            i--;
        }
        int t = lower_bound(suf.begin(),suf.end(),x)-suf.begin();
        if(t!=n)
        {
            if(suf[t]==x) ans = min(ans,t+1);
        }
        while(i>=0)
        {
            int d = x-sm;
            t = lower_bound(suf.begin(),suf.end(),d)-suf.begin();
            if(t+i<n-1)
            {
                if(suf[t]==d) ans = min(ans,t+i+2);
            }
            sm -= nums[i];
            i--;
        }
        return ans==INT_MAX?-1:ans;
    }
};