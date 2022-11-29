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
    bool prune(TreeNode *root)
    {
        if (root == NULL)
        {
            return false;
        }

        bool left = prune(root->left);
        bool right = prune(root->right);
        if (left == false)
        {
            root->left = NULL;
        }
        if (right == false)
        {
            root->right = NULL;
        }

        if (root->val == 1 || left == true || right == true)
        {
            return true;
        }
        return false;
    }

    TreeNode *pruneTree(TreeNode *root)
    {
        bool check = prune(root);
        if (check == 0)
        {
            return NULL;
        }
        return root;
    }
};