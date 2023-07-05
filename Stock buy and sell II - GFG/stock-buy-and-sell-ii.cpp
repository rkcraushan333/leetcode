//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int f(vector<int>&v,vector<vector<int>>&dp,int i=0,bool b = 0){
        if(i==v.size()) return 0;
        int &rkc = dp[i][b];
        if(rkc!=-1) return rkc;
        int ans = 0;
        if(b)
        {
            ans = max(ans,f(v,dp,i+1,b));
            ans = max(ans,v[i]+f(v,dp,i+1,!b));
        }
        else
        {
            ans = max(ans,f(v,dp,i+1,b));
            ans = max(ans,(-1*v[i])+f(v,dp,i+1,!b));
        }
        return rkc = ans;
    } 
    int stockBuyAndSell(int n, vector<int> &prices) 
    {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(prices,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends