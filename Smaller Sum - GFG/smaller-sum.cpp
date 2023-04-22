//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
#define ll long long
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>v = arr;
        sort(v.begin(),v.end());
        vector<ll>p(arr.size());
        p[0] = v[0];
        for(int i=1;i<v.size();i++) {p[i] =v[i]; p[i] += p[i-1]; }
        vector<ll>res;
        for(auto i:arr){
            int t = lower_bound(v.begin(),v.end(),i)-v.begin();
            if(t==0){
                res.push_back(0);
            }else{
                res.push_back(p[t-1]);
            }
        }
        return res;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends