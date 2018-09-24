/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (!root)
            return;
        queue<TreeLinkNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            TreeLinkNode *last = q.front();
            q.pop();
            if (last->left)
                q.push(last->left);
            if (last->right)
                q.push(last->right);
            for (int i = 1; i < size; i++)
            {
                TreeLinkNode *p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                last->next = p;
                last = p;
            }
            last->next = NULL;
        }
    }
};