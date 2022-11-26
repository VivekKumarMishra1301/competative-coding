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
    void preordertraverse(TreeNode *phlaroot, TreeNode *dusraroot, int height)
    {
        if (phlaroot == NULL)
        {
            return;
        }

        if (height % 2 == 0)
        {
            swap(phlaroot->val, dusraroot->val);
        }

        preordertraverse(phlaroot->left, dusraroot->right, height + 1);
        preordertraverse(phlaroot->right, dusraroot->left, height + 1);
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        preordertraverse(root->left, root->right, 0);
        return root;
    }
};