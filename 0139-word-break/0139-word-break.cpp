class Solution {
public:
    int dp[301];
    unordered_set<string>hash; 
    bool f(string &s,int i=0)
    {
        if(i==s.size()) return true;
        int &rkc = dp[i];
        if(rkc!=-1) return rkc;
        bool ans = false;
        string t = "";
        for(int j=i;j<s.size();j++)
        {
            t += s[j];
            if(hash.count(t))
            {
                ans |= f(s,j+1);
            }
        }
        return rkc = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict) hash.insert(i);
        return f(s);
    }
};