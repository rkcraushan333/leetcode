//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define ll long long
    ll dp[1001][1001];
    ll f(int coins[],int n,int sum,int i=0)
    {
        if(sum==0) return 1;
        if(i==n||sum<0) return 0;
        ll &rkc = dp[i][sum];
        if(rkc!=-1) return rkc;
        ll ans = 0;
        ans += f(coins,n,sum-coins[i],i);
        ans += f(coins,n,sum,i+1);
        return rkc = ans;
    }
    long long int count(int coins[], int N, int sum) 
    {
        memset(dp,-1,sizeof(dp));
        return f(coins,N,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends