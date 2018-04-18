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
        vector<vector<int> > res;
        if(root==NULL) return res;
        queue<TreeNode*> curr;
        curr.push(root);
        vector<int> level;
        
        while(!curr.empty()){
            int size = curr.size();
            for(int i=0;i<size;i++){
                root= curr.front();
                level.push_back(root->val);
                curr.pop();
                if(root->left){
                    curr.push(root->left);
                }
                if(root->right){
                    curr.push(root->right);
                }
            }
            res.push_back(level);
            level.clear();
        }
        return res;
        
        
        
    }
};
