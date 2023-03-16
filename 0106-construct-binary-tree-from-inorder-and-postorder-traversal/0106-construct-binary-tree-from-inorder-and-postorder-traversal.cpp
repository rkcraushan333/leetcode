class Solution {
public:
    TreeNode* Build(vector<int>&in,vector<int>&post,int s1,int e1,int s2,int e2){
        if(s1>e1 || s2>e2) return NULL;
        TreeNode* root = new TreeNode();
        int node;
        for(int i=s1;i<=e1;i++){
            if(post[e2]==in[i]){
                node = i;
                break;
            }
        }
        root->val = in[node];
        root->left = Build(in,post,s1,node-1,s2,s2+node-s1-1);
        // cout<<node+1<<" "<<e1<<" "<<" "<<s2+node-s1<<" "<<e2-1<<endl;
        root->right = Build(in,post,node+1,e1,s2+node-s1,e2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return Build(inorder,postorder,0,n-1,0,n-1);
    }
};