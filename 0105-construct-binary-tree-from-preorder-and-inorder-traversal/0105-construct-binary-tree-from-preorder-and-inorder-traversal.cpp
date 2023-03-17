class Solution {
public:
    TreeNode* Build(vector<int>&pre,vector<int>&in,int s1,int e1,int s2,int e2){
        if(s1>e1 ||s2>e2) return NULL;
        TreeNode* node = new TreeNode();
        int root;
        for(int i=s2;i<=e2;i++){
            if(pre[s1]==in[i]){
                root = i;
                break;
            }
        }
        node->val = pre[s1];
        node->left = Build(pre,in,s1+1,s1+root-s2,s2,root-1);
        node->right = Build(pre,in,s1+root-s2+1,e1,root+1,e2);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
        int n = preorder.size();
        return Build(preorder,inorder,0,n-1,0,n-1);
    }
};