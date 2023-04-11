//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(),arr.begin()+n/2);
        int j=n/2,cnt =0;
        while(j<n){
            if(arr[n/2-1]<5*arr[j]) {j++; continue;}
            int t = lower_bound(arr.begin(),arr.begin()+n/2,5*arr[j])-arr.begin();
            cnt += n/2-t;
            j++;
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends