// Dp on Tree
class Solution {
public:
    map<pair<TreeNode*,int>,int>dp;
    int f(TreeNode* root,int flag)
    {
        if(!root) return 0;
        if(dp.count({root,flag})) return dp[{root,flag}];
        int ans;
        if(flag)
        {
            int a = f(root->left,1)+f(root->right,1);
            int b = root->val + f(root->left,0)+f(root->right,0);
            ans = max(a,b);
        }
        else
        {
            ans = f(root->left,1)+f(root->right,1);
        }
        return dp[{root,flag}] = ans;
    }
    int rob(TreeNode* root) 
    {
        return f(root,1);
    }
};