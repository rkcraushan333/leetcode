class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) 
    {
        int ans = 0;
        int i1=0,i2=0,j=0,curt1=0,curf1=0,curt2=0,curf2=0;
        int n = s.size();
        while(j<n)
        {
            if(s[j]=='T') 
            {
                curt1++; curt2++;
            }
            else 
            {
                curf1++; curf2++;
            }
            while(curf1>k)
            {
                if(s[i1]=='F') curf1--;
                else curt1--;
                i1++;
            }
            while(curt2>k)
            {
                if(s[i2]=='F') curf2--;
                else curt2--;
                i2++;
            }
            ans = max(ans,j-i1+1);
            ans = max(ans,j-i2+1);
            j++;
        }
        return ans;
    }
};