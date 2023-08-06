class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s = to_string(n);
        bool val = next_permutation(s.begin(),s.end());
        if(val==false) return -1;
        long long a = stol(s);
        if(a>INT_MAX) return -1; 
        return a;
    }
};