//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int n)
    {
        vector<int>v = arr;
        map<int,int>m;
        sort(arr.begin(),arr.end());
        int cnt = 1;
        for(int i=0;i<n;i++)
        {
            if(!m.count(arr[i]))
            {
                m[arr[i]] = cnt;
                cnt++;
            }
        }
        vector<int>res;
        for(auto i:v)
        {
            res.push_back(m[i]);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends