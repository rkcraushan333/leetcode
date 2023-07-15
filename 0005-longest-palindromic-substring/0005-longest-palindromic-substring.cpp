// Time complexity O(n^2)+O(n^2) == O(n^2)
// space complexity O(n^2)
class Solution {
public:
    int dp[1001][1001];
    bool isPal(string &s,int i,int j)
    {
        if(i>=j) return 1;
        int &rkc = dp[i][j];
        if(rkc!=-1) return rkc;
        return rkc = isPal(s,i+1,j-1)&(s[i]==s[j]);
    }
    string longestPalindrome(string &s) 
    {
        memset(dp,-1,sizeof(dp));
        int a,b;
        int res = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isPal(s,i,j))
                {
                    if(j-i+1>res)
                    {
                        res = j-i+1;
                        a = i; b = j;
                    }
                }
            }
        }
        string ans = "";
        for(int i=a;i<=b;i++) ans += s[i];
        return ans;
    }
};