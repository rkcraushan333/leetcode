#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class Solution {
public:
    int minJumps(vector<int>& arr) {
        fastio();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<arr.size();i++){
            adj[arr[i]].push_back(i);
        }
        vector<int>vis(arr.size());
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int t = q.front().second;
            q.pop();
            if(i==arr.size()-1) return t;
            for(auto &x:adj[arr[i]]){
                if(!vis[x]) {q.push({x,t+1});vis[x]=1;}
            }
            if(i<arr.size()-1 && vis[i+1]==0) {q.push({i+1,t+1});vis[i+1]=1;}
            if(i>0 && vis[i-1]==0) {q.push({i-1,t+1});vis[i-1]=1;}
            adj.erase(arr[i]);
        }
        return 0;
     }
};