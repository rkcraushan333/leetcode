class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v(26),v2(26);
        for(auto i:s1) v[i-'a']++;
        int i=0,j = 0;
        while(j<s2.size()){
            v2[s2[j]-'a']++;
            if(j-i+1<s1.size()) {j++; continue;}
            if(j-i+1==s1.size()){
                if(v==v2) return true;
                v2[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        return false;
    }
};