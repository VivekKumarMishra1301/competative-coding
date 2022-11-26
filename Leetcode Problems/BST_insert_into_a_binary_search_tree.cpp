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
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *left = NULL;
        TreeNode *right = NULL;
        if (val > root->val)
        {
            right = insert(root->right, val);
        }
        else
        {
            left = insert(root->left, val);
        }

        if (left == NULL && val < root->val)
        {
            TreeNode *newNode = new TreeNode(val);
            root->left = newNode;
            return root;
        }
        if (right == NULL && val > root->val)
        {
            TreeNode *newNode = new TreeNode(val);
            root->right = newNode;
            return root;
        }
        return root;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *dalo = insert(root, val);
        if (dalo == NULL)
        {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        return root;
    }
};