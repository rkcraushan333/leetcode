class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int prev = 0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0){
            if(i>=0 && j>=0){
                if(a[i]=='0'){
                    if(b[j]=='0'){if(prev==0) ans += '0'; else{ans += '1'; prev = 0;}}
                    else{if(prev==0)ans+='1'; else ans+='0';}
                }
                else{
                    if(b[j]=='0'){if(prev==0) ans += '1'; else ans += '0';}
                    else{if(prev==0){ans+='0'; prev=1;} else{ans+='1'; prev = 1;}}
                }
                i--;
                j--;
            }
            else if(i>=0){
                if(a[i]=='0'){
                    if(prev==0) ans += '0';
                    else {ans+='1'; prev=0;}
                }else{
                    if(prev==0) ans+='1';
                    else{ans+='0'; prev=1;}
                }
                i--;
            }else{
                if(b[j]=='0'){
                    if(prev==0) ans += '0';
                    else {ans+='1'; prev=0;}
                }else{
                    if(prev==0) ans+='1';
                    else{ans+='0'; prev=1;}
                }
                j--;
            }
        }
        if(prev==1) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};