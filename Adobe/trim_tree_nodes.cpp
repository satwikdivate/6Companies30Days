//  TreeNode* trimBST(TreeNode* root, int low, int high) {
        
//         return trim(root,low,high);
//     }

//     TreeNode * trim(TreeNode * root,int low,int high){

//         if(root==NULL)
//             return NULL;
        
//         TreeNode *left=trim(root->left,low,high);
//         if(root->left!=left)
//             root->left=left;

//         TreeNode *right=trim(root->right,low,high);
//         if(root->right!=right)
//             root->right=right;
        
//         if(root->val>high || root->val <low)
//             return (root->left)? root->left :root->right;
        
//         return root;

//     }