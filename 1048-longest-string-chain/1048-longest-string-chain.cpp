class Solution {
public:
    static bool compare(string &s,string &t)
    {
        return s.size()<t.size();
    }
    set<pair<int,int>>mp;
    int fun(vector<string>&words,int i,int j,vector<vector<int>>&dp)
    {
        if(i==words.size()) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int ans = 0;
        if(j==-1)
        {
            ans = max(ans,1+fun(words,i+1,i,dp));
            ans = max(ans,fun(words,i+1,j,dp));
        }
        else
        {
            if(mp.find({j,i})!=mp.end())
            {
                ans = max(ans,1+fun(words,i+1,i,dp));
                ans = max(ans,fun(words,i+1,j,dp));
            }
            else
            {
                ans = max(ans,fun(words,i+1,j,dp));
            }
        }
        return dp[i][j+1] = ans;
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
            string s1 = words[i],s2 = words[j];
            int i1=0,j1=0,cnt=0;
            while(i1<s1.size()&&j1<s2.size())
            {
                if(s1[i1]==s2[j1])
                {
                    i1++;
                    j1++;
                }
                else
                {
                    cnt++;
                    j1++;
                }
            }
             bool take = 1;
            cnt += (s1.size()-i1)+(s2.size()-j1);
            if(cnt!=1) take = 0; 
            if(take==1) mp.insert({i,j});
        }
    }
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return fun(words,0,-1,dp);
    }
};