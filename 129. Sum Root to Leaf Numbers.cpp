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
    vector<int> nums;
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, root->val);
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        return sum;
    }
    void dfs(TreeNode *root, int cur)
    {
        if (!root->left && !root->right)
            nums.push_back(cur);
        if (root->left)
            dfs(root->left, cur * 10 + root->left->val);
        if (root->right)
            dfs(root->right, cur * 10 + root->right->val);
    }
};