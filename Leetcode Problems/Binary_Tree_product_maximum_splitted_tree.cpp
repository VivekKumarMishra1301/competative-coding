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
    long long hold = 0;

    long long product(TreeNode *root, long long total)
    {
        if (root == NULL)
        {
            return 0;
        }
        long long totalsub = 0;
        totalsub += product(root->left, total);
        totalsub += product(root->right, total);
        totalsub += root->val;
        long long val = ((total - totalsub) * totalsub);
        hold = max(hold, val);
        return totalsub;
    }

    int sum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return root->val + sum(root->left) + sum(root->right);
    }

    int maxProduct(TreeNode *root)
    {
        int total = sum(root);
        long long ans = product(root, total);
        return hold % 1000000007;
    }
};