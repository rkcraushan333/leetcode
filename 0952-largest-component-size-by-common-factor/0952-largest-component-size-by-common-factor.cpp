class Solution {
public:
    int par[100001];
    int size[100001];
    int find(int a){
        if(par[a]==a) return a;
        return par[a] = find(par[a]);
    }
    void unionset(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            par[b] = a;
            size[a] += size[b];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        for(int i=0;i<100000;i++) {par[i] = i;size[i]=1;}
        unordered_set<int>s;
        int n = 0;
        for(int i=0;i<nums.size();i++) {s.insert(nums[i]); n= max(n,nums[i]);}
        for(int i=2;i<=n;i++){
            int last = -1;
            for(int j=i;j<=n;j+=i){
                if(s.find(j)!=s.end()){
                    if(last==-1){
                        last = j;
                    }else{
                        unionset(last,j);
                    }
                }
            }
        }
        int res = 1;
        for(auto &i:s){
            res = max(res,size[i]);           
        }
        cout<<par[4]<<endl;
        cout<<par[6]<<endl;
        cout<<par[15]<<endl;
        cout<<par[35]<<endl;
        return res;
    }
};