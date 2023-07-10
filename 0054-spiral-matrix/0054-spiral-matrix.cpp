class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size(),m = a[0].size();
        int i1 = 0,i2 = n-1,j1 = 0,j2 = m-1;
        vector<int>res;
 		while(i1<=i2 && j1<=j2)
 		{
 		    for(int x=j1;x<=j2;x++)
 		    {
 		        res.push_back(a[i1][x]);
 		    }
 		    i1++;
 		    for(int x=i1;x<=i2;x++)
 		    {
 		        res.push_back(a[x][j2]);
 		    }
 		    j2--;
 		    if(i1<=i2){for(int x=j2;x>=j1;x--)
 		    {
 		        res.push_back(a[i2][x]);
 		    }}
 		    i2--;
 		    if(j1<=j2){for(int x=i2;x>=i1;x--)
 		    {
 		        res.push_back(a[x][j1]);
 		    }}
 		    j1++;
 		}
 		return res;
    }
};