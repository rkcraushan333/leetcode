// Using DFS in graph
class Solution {
public:
    map<int,vector<int>>adj;
    unordered_set<int>vis;
    vector<int>res;
    void build_graph(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                adj[root->val].push_back(root->left->val);
                adj[root->left->val].push_back(root->val);
                build_graph(root->left);
            }
            if(root->right)
            {
                adj[root->val].push_back(root->right->val);
                adj[root->right->val].push_back(root->val);
                build_graph(root->right);
            }
        }
    }
    void dfs(int s,int k)
    {
        vis.insert(s);
        if(k==0)
        {
            res.push_back(s);
            return;
        }
        for(auto child:adj[s])
        {
            if(!vis.count(child))
            {
                dfs(child,k-1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        build_graph(root);
        dfs(target->val,k);
        return res;
    }
};