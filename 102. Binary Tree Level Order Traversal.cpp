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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *f = q.front();
                q.pop();
                tmp.push_back(f->val);
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};