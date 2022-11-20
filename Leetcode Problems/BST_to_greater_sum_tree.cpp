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
    int gst(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return sum;
        }
        sum = gst(root->right, sum);
        sum = sum + root->val;
        root->val = sum;
        sum = gst(root->left, sum);
        return sum;
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        int greater = gst(root, 0);
        return root;
    }
};