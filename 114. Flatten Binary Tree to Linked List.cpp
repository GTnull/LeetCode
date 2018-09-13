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
    vector<TreeNode *> nodes;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->left = NULL;
        nodes[nodes.size() - 1]->right = NULL;
    }
    void dfs(TreeNode *root)
    {
        if (root)
            nodes.push_back(root);
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
    }
};