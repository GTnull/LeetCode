/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    //f1(node) = max( f2(node->left) + f2(node->right) + node->val, f2(node))
    //f2(node) = f1(node->left) + f1(node->right)
    int rob(TreeNode *root)
    {
        return dfs(root).first;
    }
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return make_pair(0, 0);
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        int f2 = l.first + r.first;
        int f1 = max(l.second + r.second + root->val, f2);
        return make_pair(f1, f2);
    }
};