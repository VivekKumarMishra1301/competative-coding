/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxpath = -1001;

    int traverse(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = traverse(root->left);
        int right = traverse(root->right);
        if (left == 0 && right == 0 && root->val < 0)
        {

            maxpath = max(maxpath, root->val);
            return 0;
        }
        maxpath = max(maxpath, left + right + root->val);
        maxpath = max(maxpath, right + root->val);
        maxpath = max(maxpath, left + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        int get = traverse(root);
        return maxpath;
    }
};