//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(int mid,vector<vector<int>>&m){
        int cnt = 0;
        for(auto v:m){
            int t = upper_bound(v.begin(),v.end(),mid)-v.begin();
            cnt += t;
        }
        return cnt>(m.size()*m[0].size())/2;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here       
        int s = 0,e = 1e4;
        while(e-s>1){
            int mid = (s+e)/2;
            if(check(mid,matrix)) e = mid;
            else s = mid;
        }
        return e;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends