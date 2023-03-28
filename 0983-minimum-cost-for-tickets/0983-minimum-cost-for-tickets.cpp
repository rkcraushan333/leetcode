class Solution {
public:
    int dp[366][367][5];
    int f(vector<int>&days,vector<int>&costs,int last = -1,int i = 0,int taken = -1){
        if(i==days.size()) return 0;
        int &t = dp[i][last+1][taken+1];
        if(t!=-1) return t;
        int res = 1e8;
        if(taken==0 ||taken ==-1){
            res = min(res,costs[0]+f(days,costs,i,i+1,0));
            res = min(res,costs[1]+f(days,costs,i,i+1,1));
            res = min(res,costs[2]+f(days,costs,i,i+1,2));
        }else if(taken==1){
            if(days[i]-days[last]<7){
                res = min(res,f(days,costs,last,i+1,taken));
            }else{
                res = min(res,costs[0]+f(days,costs,i,i+1,0));
            res = min(res,costs[1]+f(days,costs,i,i+1,1));
            res = min(res,costs[2]+f(days,costs,i,i+1,2));
            }
        }else if(taken==2){
            if(days[i]-days[last]<30){
                res = min(res,f(days,costs,last,i+1,taken));
            }else{
                res = min(res,costs[0]+f(days,costs,i,i+1,0));
                res = min(res,costs[1]+f(days,costs,i,i+1,1));
                res = min(res,costs[2]+f(days,costs,i,i+1,2));
            }
        }
        return t=res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return f(days,costs);
    }
};