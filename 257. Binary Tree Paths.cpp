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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        if (!root)
        {
            return ret;
        }
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, paths, path);
        for (int i = 0; i < paths.size(); i++)
        {
            string tmp = "";
            if (paths[i].size() == 1)
                tmp += to_string(paths[i][0]);
            else
            {
                tmp = tmp + to_string(paths[i][0]);
                for (int j = 1; j < paths[i].size(); j++)
                    tmp += "->" + to_string(paths[i][j]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
    void dfs(TreeNode *root, vector<vector<int>> &paths, vector<int> &path)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        if (root->left)
            dfs(root->left, paths, path);
        if (root->right)
            dfs(root->right, paths, path);
        path.pop_back();
    }
};