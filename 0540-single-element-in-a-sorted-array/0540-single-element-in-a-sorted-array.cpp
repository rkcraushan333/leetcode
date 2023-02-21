class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int s = 0,e = n-1;
        while(s<e){
            int m = (s+e)/2;
            if((m!=n-1) && v[m]==v[m+1]){
                if((n-m)%2==0)
                    e = m-1;
                else 
                    s = m+1;
            }else if((m!=0) && v[m]==v[m-1]){
                if((n-m)%2==0)
                    s = m+1;
                else
                    e = m-1;
            }else
                return v[m];
        }
        return v[s];
    }
};