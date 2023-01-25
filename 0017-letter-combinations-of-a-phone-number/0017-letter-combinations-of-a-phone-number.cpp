class Solution {
public:
    vector<string>v;
    vector<string>res;
    void f(string &s,int i=0,string t=""){
        if(i==s.size()){
            if(t.size())res.push_back(t);
            return;
        }
        string k = v[s[i]-'0'];
        for(char &c:k){
            f(s,i+1,t+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        char c ='a';
        v.resize(10);
        for(int i=2;i<10;i++){
            string s= "";
            if(i==7||i==9){
                int x =4;
                while(x--){s += c;
                c++;}
                v[i]= s;
            }else{
                int x =3;
                while(x--){s += c;
                c++;}
                v[i] = s;
            }
        }
        f(digits);
        return res;
    }
};