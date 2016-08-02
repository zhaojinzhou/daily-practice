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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  res;
        vector<int>  level;
        queue<TreeNode *> curr ,next;
        if(!root) return res;
        curr.push(root);
        int i=0;
        while(!curr.empty()){
            while(!curr.empty()){
                root=curr.front();
                curr.pop();
                level.push_back(root->val);
            if(root->left) next.push(root->left);
            if(root->right) next.push(root->right);
            
            
            }
            
            i++;
            if(i%2==0)  reverse(level.begin(),level.end());
            res.push_back(level);
            swap(curr,next);
            level.clear();
            
            
            
            
            
            
        }
        return res;
        
    }
};