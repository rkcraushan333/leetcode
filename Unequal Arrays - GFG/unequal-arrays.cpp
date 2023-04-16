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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        long long a = accumulate(A.begin(),A.end(),0);
        long long b = accumulate(B.begin(),B.end(),0);
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        if(a!=b) return -1;
        vector<int>ao,ae,bo,be;
        for(auto i:A){
            if(i&1) ao.push_back(i);
            else ae.push_back(i);
        }
        for(auto i:B){
            if(i&1) bo.push_back(i);
            else be.push_back(i);
        }
        if(ao.size()!=bo.size()) return -1;
        if(ae.size()!=be.size()) return -1;
        long long asum = 0,bsum =0;
        for(int i=0;i<ao.size();i++){
            asum += abs(ao[i]-bo[i]);
        }
        for(int i=0;i<ae.size();i++){
            bsum += abs(ae[i]-be[i]);
        }
        return (asum+bsum
        )/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends