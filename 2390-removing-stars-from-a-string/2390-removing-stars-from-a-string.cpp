class Solution {
public:
    string removeStars(string s) {
        string str;
        int cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*') cnt++;
            else{
                if(!cnt) str.push_back(s[i]);
                else cnt--;
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};