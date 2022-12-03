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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val != key)
        {
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }

        TreeNode *left = deleteNode(root->left, key);
        TreeNode *right = deleteNode(root->right, key);

        if (left != NULL && right != NULL)
        {
            TreeNode *temp = right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = left;
            return right;
        }
        else if (left == NULL && right != NULL)
        {
            return right;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else
        {
            return NULL;
        }
    }
};