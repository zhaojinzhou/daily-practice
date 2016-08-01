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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        stack<bool> flag;
        while(root||!sta.empty()){
            while(root){
                
                sta.push(root);
                flag.push(0);
                root=root->left;
            }
            if(flag.top()==0){
            root=sta.top();
            flag.top()=1;
            root=root->right;
            }
            else{
                root=sta.top();
                sta.pop();
                flag.pop();
                res.push_back(root->val);
               root=NULL;
                
            }
           
        
        }
         return res;
        
    }
};