class Solution {
public:
    int dp[100001][2];
    map<int,vector<int>>m;
    int f(vector<int>&v,int d,int i = 0,bool b = 0)
    {
        int &rkc = dp[i][b];
        if(rkc!=-1) return rkc;
        int cnt;
        if(b)
        {
            cnt = 0;
            int a = v[i]+d;
            if(m.find(a)!=m.end())
            {
                int t = upper_bound(m[a].begin(),m[a].end(),i)-m[a].begin();
                if(t<m[a].size())
                {
                    cnt = 1+f(v,d,m[a][t],1);
                }
            }
        }
        else
        {
            cnt = 1;
            for(int j=i;j<v.size();j++)
            {
                int a = v[j]+d;
                if(m.find(a)!=m.end())
                {
                    int t = upper_bound(m[a].begin(),m[a].end(),j)-m[a].begin();
                    if(t<m[a].size())
                    {
                        cnt = max(cnt,2+f(v,d,m[a][t],1));
                    }
                }
            }
        }
        return rkc=cnt;
    }
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        return f(arr,difference);
    }
};