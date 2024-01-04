#include<bits/stdc++.h>
#include<random>
using namespace std;
 struct info{

        int value;
        bool isBst;
        int min;
        int max;
    };
    
class Solution {
public:

    info f(TreeNode *root,int &ans){

        if(root==NULL)
            return {0,true,INT_MAX,INT_MIN};
        

       info left=f(root->left,ans);
        info right=f(root->right,ans);

        info current;
        current.value=left.value+right.value+root->val;
        // calcute maximum and minimum
        current.min=min(root->val,min(left.min,right.min));
        current.max=max(root->val,max(left.max,right.max));
       if(left.isBst && right.isBst && (root->val >left.max && root->val <right.min)){
          
            current.isBst=true;
        }else
             current.isBst=false;

        if(current.isBst)
              ans=max(current.value,ans);
            // return {sum,true,}
            return current;

    }
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;

        f(root,ans);
        if(ans==INT_MIN || ans<0)
            return 0;
        return ans;
    }