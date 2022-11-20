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
    int result = 0;
    int sumnodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = sumnodes(root->left);
        int right = sumnodes(root->right);
        result = result + abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode *root)
    {
        int tilted = sumnodes(root);
        return result;
    }
};