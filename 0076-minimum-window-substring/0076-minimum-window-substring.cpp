class Solution {
public:
    string minWindow(string s, string t) {
        int i1,j1,i=0,j=0,curr = 1e8;
        vector<int>v1(60),v2(60);
        for(auto x:t){
            v1[x-'A']++;
        }
        while(j<s.size()){
            v2[s[j]-'A']++;
            while(1){
                bool t = 1;
                for(int x=0;x<60;x++){
                   if(v2[x]<v1[x])
                   {
                      t = 0;
                      break;
                   }
                }
                if(t){
                    if(curr>j-i+1){
                        curr = j-i+1;
                        j1 = j;
                        i1 = i;
                    }
                    v2[s[i]-'A']--;
                    i++;
                }
                else
                    break;
            }
            j++;
        }
        if(curr==1e8) return "";
        return s.substr(i1,curr);
    }
};