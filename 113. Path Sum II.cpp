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
    vector<vector<int>> ret;
    vector<int> cur;
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root)
            pathSum(root, 0, sum);
        return ret;
    }
    void pathSum(TreeNode *root, int curr, int target)
    {
        curr += root->val;
        cur.push_back(root->val);
        if (!root->left && !root->right && curr == target)
        {
            ret.push_back(cur);
        }
        else
        {
            if (root->left)
                pathSum(root->left, curr, target);
            if (root->right)
                pathSum(root->right, curr, target);
        }
        curr -= root->val;
        cur.pop_back();
    }
};