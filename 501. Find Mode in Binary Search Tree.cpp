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
    vector<int> res;
    int cur_num;
    int cur_max;
    TreeNode* pre;
    vector<int> findMode(TreeNode* root) {
        cur_num = 0;
        cur_max = 0;
        pre = NULL;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root)   
            return;
        dfs(root->left);
        
        if(pre && root->val == pre->val)
            cur_num++;
        else
            cur_num = 1;
        pre = root;
        if(cur_num == cur_max)
            res.push_back(root->val);
        else if(cur_num > cur_max){
            res.clear();
            res.push_back(root->val);
            cur_max = cur_num;
        }
        
        dfs(root->right);
    }
};