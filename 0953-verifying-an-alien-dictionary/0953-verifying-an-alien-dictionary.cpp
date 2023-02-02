class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order){
      vector<int>v(26);
      for(int i=0;i<26;i++) v[order[i]-'a'] = i;
      for(int i=0;i<words.size();i++){
          for(int j=i+1;j<words.size();j++){
              string s = words[j],t = words[i];
              int a = 0, b = 0;
              while(a<s.size()&&b<t.size()){
                  if(s[a]!=t[b]){
                      if(v[t[b]-'a']>v[s[a]-'a']) 
                          return false;
                      else break;
                    }
                  a++;
                  b++;
                  }
              if(a==s.size()) if(s<t) return false;
      }
      }
      return true;
    }
};