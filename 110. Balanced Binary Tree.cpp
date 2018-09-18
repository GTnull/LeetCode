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
    bool isBalanced(TreeNode* root) {
        return check(root, 0).second;
    }
    pair<int, bool> check(TreeNode* root, int depth){
        if(!root)
            return {0, true};
        pair<int, bool> left = check(root->left, depth);
        pair<int, bool> right = check(root->right, depth);
        int cur_depth = max(left.first, right.first) + 1;
        bool cur_balanced = left.second && right.second && abs(left.first - right.first) <= 1;
        return {cur_depth, cur_balanced};
    }
};