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
    int count = 0;

    void traverse(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val >= val)
        {
            count++;
        }
        traverse(root->left, max(root->val, val));
        traverse(root->right, max(root->val, val));
    }

    int goodNodes(TreeNode *root)
    {
        traverse(root, root->val);
        return count;
    }
};