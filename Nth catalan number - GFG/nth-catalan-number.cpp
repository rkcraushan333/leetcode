//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    const int mod = 1e9+7;
    int dp[1001][1001];
    int f(int n,int l=0)
    {
        if(n==0) return l==0;
        if(l>n) return 0;
        int &rkc = dp[n][l];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(l==0)
        {
            ans += f(n,l+1);
            ans %= mod;
        }
        else
        {
            ans += f(n,l+1); ans %= mod;
            ans += f(n-1,l-1); ans %= mod;
        }
        return rkc = ans;
    }
    int findCatalan(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends