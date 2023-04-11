class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str,str2;
        int cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#') cnt++;
            else{
                if(!cnt) str.push_back(s[i]);
                else cnt--;
            }
        }
        cnt = 0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#') cnt++;
            else{
                if(!cnt) str2.push_back(t[i]);
                else cnt--;
            }
        }
        reverse(str.begin(),str.end());
        reverse(str2.begin(),str2.end());
        return str==str2;
    }
};