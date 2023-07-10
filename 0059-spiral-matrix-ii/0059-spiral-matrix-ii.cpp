class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i1 = 0,j1 = 0,i2 = n-1,j2 = n-1,cnt=1;
        vector<vector<int>>res(n,vector<int>(n));
        while(i1<=i2&&j1<=j2)
        {
            for(int x =j1;x<=j2;x++)
            {
                res[i1][x] = cnt++;
            }
            i1++;
            for(int x=i1;x<=i2;x++)
            {
                res[x][j2] = cnt++;
            }
            j2--;
            for(int x=j2;x>=j1;x--) // there is no need of base case due to n*n
            {
                res[i2][x] = cnt++;
            }
            i2--;
            for(int x=i2;x>=i1;x--)
            {
                res[x][j1] = cnt++;
            }
            j1++;
        }
        return res;
    }
};