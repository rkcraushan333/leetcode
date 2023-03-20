class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int cnt = 0,t = v.size()-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                int i1 = i-1,i2=i+1;
                i1 = max(0,i1);
                i2 = min(t,i2);
                if(v[i1]==0 && v[i2]==0)
                    {
                       cnt++;
                       v[i] =1;
                    }
            }
        }
        return cnt>=n;
    }
};