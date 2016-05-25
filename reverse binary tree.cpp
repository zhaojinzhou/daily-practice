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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *root1=root;
        if(root){
        swap(root->left,root->right);
            
        
        }
        else return root1;
        invertTree(root->left);
        invertTree(root->right);
        return root1;
        
        
    }
};