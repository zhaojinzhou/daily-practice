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
    void binaryTreePaths(vector<string>& result, TreeNode* node, string s) {
        if(!node->left && !node->right){
            result.push_back(s);
            return ;
        }
        if(node->left)binaryTreePaths(result, node->left, s+"->"+to_string(node->left->val));
        if(node->right)binaryTreePaths(result, node->right, s+"->"+to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root)return ret;
        
        binaryTreePaths(ret, root, to_string(root->val));
        return ret;
    }
};