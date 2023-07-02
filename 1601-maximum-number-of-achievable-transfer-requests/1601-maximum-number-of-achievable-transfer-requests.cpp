class Solution {
public:
    int f(vector<vector<int>>&v,vector<int>&v1,int i=0,int cnt = 0)
    {
        if(i==v.size())
        {
            for(auto i:v1)
            {
                if(i!=0)
                {
                    return 0;
                }
            }
            return cnt;
        }
        int ans = 0;
        ans = max(ans,f(v,v1,i+1,cnt));
        v1[v[i][0]]--;
        v1[v[i][1]]++;
        ans = max(ans,f(v,v1,i+1,cnt+1));
        v1[v[i][0]]++;
        v1[v[i][1]]--;
        return ans;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int>v(n);
        return f(requests,v);
    }
};