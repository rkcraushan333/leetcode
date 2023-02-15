class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int prev = 0,i=0;
        reverse(num.begin(),num.end());
        while(k){
            if(i<num.size()){
                int t = (k%10)+num[i]+prev;
                num[i] = t%10;
                prev = t/10;
            }else{
                int t = (k%10)+prev;
                prev = t/10;
                num.push_back(t%10);
            }
            k /= 10;
            i++;
        }
        if(prev!=0){
            if(i<num.size()){
                while(i<num.size()){
                    int t = num[i]+prev;
                    num[i] = t%10;
                    prev = t/10;
                    i++;
                }
                if(prev!=0) num.push_back(prev);
            }
            else num.push_back(prev);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};