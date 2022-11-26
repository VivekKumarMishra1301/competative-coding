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
    bool traverse(TreeNode *root, int target)
    {
        if (root == NULL)
        {
            return true;
        }

        bool left = traverse(root->left, target);
        bool right = traverse(root->right, target);

        if (left)
        {
            root->left = NULL;
        }
        if (right)
        {
            root->right = NULL;
        }

        if (root->left == NULL && root->right == NULL && root->val == target)
        {
            return true;
        }
        return false;
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        bool check = traverse(root, target);
        if (check)
        {
            root = NULL;
        }
        return root;
    }
};