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
    void traverse(TreeNode *root, vector<vector<int>> &hold, vector<int> &hold1, int k, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        hold1.push_back(root->val);
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL && sum == k)
        {
            hold.push_back(hold1);
            hold1.pop_back();
            return;
        }

        traverse(root->left, hold, hold1, k, sum);
        traverse(root->right, hold, hold1, k, sum);
        hold1.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> hold;
        vector<int> hold1;
        traverse(root, hold, hold1, targetSum, 0);
        return hold;
    }
};