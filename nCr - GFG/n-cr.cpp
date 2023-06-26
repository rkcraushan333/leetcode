//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int mod = 1e9+7;
    long long fac[1001];
    void f()
    {
        fac[0] = 1;
        for(int i=1;i<1001;i++)
        {
            fac[i] = i*fac[i-1];
            fac[i] %= mod;
        }
    }
    int fastexpo(long long a,long long b)
    {
        a %= mod;
        long long res = 1;
        while(b>0)
        {
            if(b&1)
            {
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            b >>= 1;
        }
        return res;
    }
    int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        f();
        long long a = fac[n];
        long long b = fac[r];
        long long c = fac[n-r];
        // cout<<a<<" "<<b<<" "<<c<<endl;
        b *= c;
        b %= mod;
        // find inverse of b
        long long d = b,e = mod-2;
        long long ans = fastexpo(d,e)%mod;
        ans *= a;
        ans %= mod;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends