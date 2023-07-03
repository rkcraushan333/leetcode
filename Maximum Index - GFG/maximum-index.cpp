//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
int maxIndexDiff(int arr[], int n) {
        vector<bool> hasGrt(n); 
        int maxi = 0;
        for(int i=n-1; i>=0; i--){
            if(maxi >= arr[i])
                hasGrt[i] = 1;
            maxi = max(maxi, arr[i]);
        }
        
        int x = 0;
        for(int i=0; i<n; i++)
            if(hasGrt[i]){ //optimization #1
                for(int j=n-1; j>=i+x; j--) //j >= i+x (optimization #2, run loop only until there are chances of getting a better x)
                    if(arr[j] >= arr[i]){
                        x = j-i;
                        break; // can no longer maximise x
                    }
            }
            
        return x;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends