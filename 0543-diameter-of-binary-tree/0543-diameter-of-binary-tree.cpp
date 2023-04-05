class Solution {
public:
    int diameter = 0;
    int f(TreeNode* root){
        if(!root) return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        diameter = max(diameter,lh+rh+1);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = f(root);
        return diameter-1;
    }
};