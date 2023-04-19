class Solution {
public:
    int maxStep = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxStep;
    }
    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root) return;
        maxStep = max(maxStep, step); 
        if (isLeft) {
            dfs(root->left, false, step + 1);
            dfs(root->right, true, 1);
        } else {
            dfs(root->right, true, step + 1);
            dfs(root->left, false, 1);
        }
    }
};