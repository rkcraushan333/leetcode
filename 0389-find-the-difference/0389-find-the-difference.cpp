class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int x=0;
        for(auto c:t) x^=(c-'a');
        for(auto c:s) x^= (c-'a');
        return 'a'+x;
    }
};