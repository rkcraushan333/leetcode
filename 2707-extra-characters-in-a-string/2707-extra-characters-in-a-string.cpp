class Solution {
public:
    unordered_set<string>hash;
    int dp[51];
    int f(string &s,int i=0)
    {
        if(i==s.size()) return 0;
        int &rkc = dp[i];
        if(rkc!=-1) return rkc;
        int ans = 1e9;
        ans = min(ans,1+f(s,i+1));
        string temp="";
        while(i<s.size())
        {
            temp += s[i];
            if(hash.count(temp))
            {
                ans = min(ans,f(s,i+1));
            }
            i++;
        }
        return rkc = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        for(auto i:dictionary) hash.insert(i);
        memset(dp,-1,sizeof(dp));
        return f(s);
    }
};