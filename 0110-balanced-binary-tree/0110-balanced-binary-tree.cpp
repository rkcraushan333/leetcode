class Solution {
public:
    int f(TreeNode* root){
        if(!root) return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        if(abs(lh-rh)>1 || lh==-1 ||rh ==-1) return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(f(root)==-1) return 0;
        return 1;
    }
};