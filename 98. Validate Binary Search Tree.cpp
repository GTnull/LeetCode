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
    vector<int> ret;
    bool isValidBST(TreeNode *root)
    {
        traverse(root);
        for (int i = 1; i < ret.size(); i++)
        {
            if (ret[i] <= ret[i - 1])
                return false;
        }
        return true;
    }
    void traverse(TreeNode *root)
    {
        if (!root)
            return;
        traverse(root->left);
        ret.push_back(root->val);
        traverse(root->right);
    }
};