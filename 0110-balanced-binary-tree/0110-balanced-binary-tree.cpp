class Solution {
public:
    pair<int,bool> f(TreeNode* root){
        if(!root) return {0,1};
        auto l = f(root->left);
        auto r = f(root->right);
        if(abs(l.first-r.first)>1) return {0,0};
        if(l.second==false || r.second==false) return {0,0};
        return {max(l.first,r.first)+1,1};
    }
    bool isBalanced(TreeNode* root) {
        return f(root).second;
    }
};