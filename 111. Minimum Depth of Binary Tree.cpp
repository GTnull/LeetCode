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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 1;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            queue<TreeNode *> next;
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            }
            depth++;
            q = next;
        }
    }
};