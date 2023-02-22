class Solution {
public:
    int dp[17][17];
    bool isPal(int i,int j,string &s){
        if(i==j) return 1;
        if(i+1==j) return s[i]==s[j];
        int &t = dp[i][j];
        if(t!=-1) return t;
        return t = (s[i]==s[j]) && (isPal(i+1,j-1,s));
    }
    vector<vector<string>>res;
    void f(string &s,int i,vector<string>&v){
        if(i==s.size()) {
            res.push_back(v);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPal(i,j,s)){
                string k = "";
                for(int a=i;a<=j;a++){
                    k += s[a];
                }
                v.push_back(k);
                f(s,j+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        memset(dp,-1,sizeof(dp));
        vector<string>v;
        f(s,0,v);
        return res;
    }
};