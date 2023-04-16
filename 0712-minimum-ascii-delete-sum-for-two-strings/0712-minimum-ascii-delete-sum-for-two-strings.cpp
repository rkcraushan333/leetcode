class Solution {
public:
    int dp[1001][1001];
    int f(string &s, string &t,int i=0,int j=0){
        if(i==s.size() && j==t.size()) return 0;
        if(i==s.size()){
            int cnt = 0;
            for(int k=j;k<t.size();k++)
                cnt += t[k];
            return cnt;
        }
        if(j==t.size()){
            int cnt = 0;
            for(int k=i;k<s.size();k++)
                cnt += s[k];
            return cnt;
        }
        int &tt = dp[i][j];
        if(tt!=-1) return tt;
        int res=1e7;
        if(s[i]==t[j])
            res = min(res,f(s,t,i+1,j+1));
        else{
            res = min(res,t[j]+f(s,t,i,j+1));
            res = min(res,s[i]+f(s,t,i+1,j));
        }
        return tt=res;
    }
    int minimumDeleteSum(string &s, string &t) {
        memset(dp,-1,sizeof(dp));
        return f(s,t);
    }
};