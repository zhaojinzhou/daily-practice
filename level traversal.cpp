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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode* > curr,next;
        vector<int> level;
        if(!root) return res;
        curr.push(root);
        while(!curr.empty()){
            while(!curr.empty()){
                root=curr.front();
                level.push_back(root->val);
                curr.pop();
                if(root->left) next.push(root->left);
                if(root->right) next.push(root->right);
                
            }
            res.push_back(level);
            swap(curr,next);
            level.clear();
            
        }
        return res;
        
    }
};