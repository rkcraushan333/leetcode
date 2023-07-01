// Using Backtracking O(k^n)
class Solution {
public:
    int f(vector<int>&v,vector<int>&v1,int k,int i=0)
    {
        if(i==v.size())
        {
            int ans = INT_MIN;
            for(int j=0;j<k;j++)
            {
                ans = max(ans,v1[j]);
            }
            return ans;
        }
        int res = 1e8;
        for(int j=0;j<k;j++)
        {
            v1[j] += v[i];
            res = min(res,f(v,v1,k,i+1));
            v1[j] -= v[i];
        }
        return res;
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int>v(k);
        return f(cookies,v,k);
    }
};