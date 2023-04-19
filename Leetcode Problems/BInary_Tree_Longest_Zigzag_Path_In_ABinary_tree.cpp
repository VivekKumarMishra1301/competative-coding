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

class zigzag
{
public:
    int frzig = -1;
    int bkzig = -1;
    int maxzig = 0;
};

class Solution
{
public:
    zigzag longest(TreeNode *root)
    {
        if (root == NULL)
        {
            zigzag ans;
            ans.frzig = -1;
            ans.bkzig = -1;
            ans.maxzig = 0;
            return ans;
        }

        zigzag left = longest(root->left);
        zigzag right = longest(root->right);
        zigzag ans;
        ans.maxzig = max(max(left.maxzig, right.maxzig), max(left.bkzig, right.frzig) + 1);
        ans.frzig = 1 + left.bkzig;
        ans.bkzig = 1 + right.frzig;
        return ans;
    }

    int longestZigZag(TreeNode *root)
    {
        return longest(root).maxzig;
    }
};