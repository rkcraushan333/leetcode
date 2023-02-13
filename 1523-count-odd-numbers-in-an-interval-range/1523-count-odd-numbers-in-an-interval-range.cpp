class Solution {
public:
    int countOdds(int a, int b) {
        if(a%2==0 && b%2==0) return (b-a)/2;
        if((a&1)&&(b&1)){
            a++;
            b--;
            return 2+(b-a)/2;
        }
    if(a&1){
        a++;
        return 1+(b-a)/2;
    }
    b--;
    return 1+(b-a)/2;
    }
};