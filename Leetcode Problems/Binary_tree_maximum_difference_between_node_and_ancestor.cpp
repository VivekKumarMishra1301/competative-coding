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
    int hold = 0;
    void traverse(TreeNode *root, int mi, int ma)
    {
        if (root == NULL)
        {
            return;
        }

        int diff1 = abs(root->val - mi);
        int diff2 = abs(root->val - ma);
        hold = max(hold, max(diff1, diff2));
        mi = min(root->val, mi);
        ma = max(root->val, ma);
        traverse(root->left, mi, ma);
        traverse(root->right, mi, ma);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        traverse(root, root->val, root->val);
        return hold;
    }
};