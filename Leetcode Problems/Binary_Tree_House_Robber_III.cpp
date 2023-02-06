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
    pair<int, int> find(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }

        pair<int, int> left = find(root->left);
        pair<int, int> right = find(root->right);
        pair<int, int> ans;
        ans.first = left.second + right.second + root->val;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        return ans;
    }

    int rob(TreeNode *root)
    {
        pair<int, int> hold = find(root);
        return max(hold.first, hold.second);
    }
};