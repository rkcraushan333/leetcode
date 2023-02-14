//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[100001][4];
    int f(vector<vector<int>>&v,int prev=0,int i=0){
        if(i==v.size()) return 0;
        if(dp[i][prev]!=-1) return  dp[i][prev];
        int res = 1e8;
        if(prev!=1){
            res = min(res,v[i][0]+f(v,1,i+1));
        }
        if(prev!=2){
            res = min(res,v[i][1]+f(v,2,i+1));
        }
        if(prev!=3){
            res = min(res,v[i][2]+f(v,3,i+1));
        }
        return dp[i][prev]=res;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        memset(dp,-1,sizeof(dp));
        return f(colors);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends