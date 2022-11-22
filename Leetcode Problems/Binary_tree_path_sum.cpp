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
    bool traverse(TreeNode *root, int sum, int k)
    {
        if (root == NULL)
        {
            return false;
        }
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL && sum == k)
        {
            return true;
        }

        bool left = traverse(root->left, sum, k);
        bool right = traverse(root->right, sum, k);
        return left || right;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return traverse(root, 0, targetSum);
    }
};