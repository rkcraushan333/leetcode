class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rc, vector<vector<string>>& ing, vector<string>& sp) 
    {
        unordered_map<string,int>us;
        int cnt = 0;
        for(int i=0;i<rc.size();i++)
        {
            if(!us.count(rc[i]))
            {
                us[rc[i]] = cnt;
                cnt++;
            }
        }
        for(auto v:ing)
        {
            for(auto i:v)
            {
                if(!us.count(i))
                {
                    us[i] = cnt;
                    cnt++;
                }
            }
        }
        queue<int>q;
        for(auto i:sp) 
        {
            if(!us.count(i))
            {
                us[i] = cnt;
                cnt++;
            }
            q.push(us[i]);
        }
        vector<vector<int>>adj(cnt);
        vector<int>indeg(cnt);
        set<int>topo;
        for(int i=0;i<rc.size();i++)
        {
            for(auto j:ing[i])
            {
                adj[us[j]].push_back(us[rc[i]]);
                indeg[us[rc[i]]]++;
            }
        }
        while(q.size())
        {
            int t = q.front(); q.pop();
            topo.insert(t);
            for(auto child:adj[t])
            {
                indeg[child]--;
                if(indeg[child]==0) q.push(child);
            }
        }
        vector<string>res;
        for(auto i:rc)
        {
            if(topo.count(us[i])) res.push_back(i);
        }
        return res;
    }
};