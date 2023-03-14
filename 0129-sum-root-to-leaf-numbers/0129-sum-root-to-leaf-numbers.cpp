/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void inorder(TreeNode* root,string s =""){
        if(!root){
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            s.push_back(root->val+'0');
            v.push_back(stoi(s));
            return;
        }
        s.push_back(root->val+'0');
        inorder(root->left,s);
        inorder(root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        inorder(root);
        return accumulate(v.begin(),v.end(),0);
    }
};