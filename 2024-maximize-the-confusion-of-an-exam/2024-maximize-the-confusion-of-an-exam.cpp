class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) 
    {
        int ans = 0;
        int i=0,j=0,curt=0,curf=0;
        int n = s.size();
        // two cases will be checked , firstly checking for max cont. T with at most k F
        while(j<n)
        {
            if(s[j]=='T') curt++;
            else curf++;
            while(curf>k)
            {
                if(s[i]=='F') curf--;
                else curt--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        i = 0; j = 0;
        curt=0; curf = 0;
        // Now checking for the 2nd case
        while(j<n)
        {
            if(s[j]=='T') curt++;
            else curf++;
            while(curt>k)
            {
                if(s[i]=='F') curf--;
                else curt--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};