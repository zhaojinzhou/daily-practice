/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        static int j=0;
        
        if(root&&(root->left&&root->right)){
            return(1+min(minDepth(root->left),minDepth(root->right)));
        }
        if(root&&(!(root->left||root->right))){
            return(1+min(minDepth(root->left),minDepth(root->right)));
        }
        if(root){
            
            return(1+max(minDepth(root->left),minDepth(root->right)));
        }
        return j;
        
    }
};