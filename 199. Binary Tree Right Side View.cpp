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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            ret.push_back(q.front()->val);
            queue<TreeNode *> tmp;
            while (!q.empty())
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->right)
                    tmp.push(cur->right);
                if (cur->left)
                    tmp.push(cur->left);
            }
            q = tmp;
        }

        return ret;
    }
};