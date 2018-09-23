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
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            stack<pair<TreeNode *, TreeNode *>> s;
            s.push(make_pair(root->left, root->right));

            while (!s.empty())
            {
                pair<TreeNode *, TreeNode *> cur = s.top();
                s.pop();
                if ((cur.first && !cur.second) || (!cur.first && cur.second))
                    return false;
                else if (cur.first)
                {
                    if (cur.first->val != cur.second->val)
                        return false;
                    s.push(make_pair(cur.first->left, cur.second->right));
                    s.push(make_pair(cur.first->right, cur.second->left));
                }
            }
        }
        return true;
    }
};