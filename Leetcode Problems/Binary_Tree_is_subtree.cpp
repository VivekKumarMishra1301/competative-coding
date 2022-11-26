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
    bool bhaibhai(TreeNode *phla, TreeNode *dusra)
    {
        if (phla == NULL && dusra == NULL)
        {
            return true;
        }
        if (phla == NULL || dusra == NULL)
        {
            return false;
        }

        if (phla->val != dusra->val)
        {
            return false;
        }

        return (phla->val == dusra->val) && bhaibhai(phla->left, dusra->left) && bhaibhai(phla->right, dusra->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
        {
            return false;
        }

        if (bhaibhai(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};