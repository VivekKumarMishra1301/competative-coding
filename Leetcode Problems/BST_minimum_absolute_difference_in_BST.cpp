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
    int result = INT_MAX;
    TreeNode *prev = NULL;

    void inordertraverse(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inordertraverse(root->left);
        if (prev != NULL)
        {
            result = min(result, root->val - prev->val);
        }
        prev = root;
        inordertraverse(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        inordertraverse(root);
        return result;
    }
};