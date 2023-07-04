//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#define ll long long
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        ll prod = 1;
        ll total = (n*(n+1))/2;
        ll ans = 0;
        int i=0,j=0;
        while(j<a.size()){
            prod *= a[j];
            while(i<=j  && prod>=k)
            {
                prod /= a[i];
                i++;
                ans += n-j;
            }
            j++;
        }
        // cout<<ans<<endl;
        return (total-ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends