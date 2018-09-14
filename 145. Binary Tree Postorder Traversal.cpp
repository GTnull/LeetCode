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
        vector<int> v;
        if(!root)   return v;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode *p = s.top(); s.pop();
            v.push_back(p->val);
            if(p->left)     s.push(p->left);
            if(p->right)    s.push(p->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};