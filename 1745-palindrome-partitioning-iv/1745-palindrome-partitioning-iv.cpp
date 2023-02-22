class Solution {
public:
    int pal[2001][2001];
    bool isPal(string &s,int i,int j){
        if(i==j) return true;
        if(i+1==j) return s[i]==s[j];
        int &t1 = pal[i][j];
        if(t1!=-1) return t1;
        return t1 = s[i]==s[j] && isPal(s,i+1,j-1);
    }
    int dp[2001][4];
    bool f(string &s,int i=0,int k=3){
        if(k==0 && i==s.size()) return 1;
        if(k==0||i==s.size()) return 0;
        int &t = dp[i][k];
        if(t!=-1) return t;
        for(int j=i;j<s.size();j++){
            if(isPal(s,i,j)){
                if(f(s,j+1,k-1))
                    return t = true;
            }
        }
        return t = false;
    }
    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
        return f(s);
    }
};