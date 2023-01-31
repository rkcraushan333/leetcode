//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        int cnt = 1;
        int i = 0,j=0;
        while(i<A.size()){
            if(A[i]==B[j]) j++;
            i++;
        }
        if(j==B.size()) return cnt;
        cnt++;
        i = 0;
        if(j==0) return -1;
        while(j<B.size()){
            if(i==A.size()) {i=0;cnt++;}
            if(A[i]!=B[j]) return -1;
            i++;
            j++;
        }
        return cnt++;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends