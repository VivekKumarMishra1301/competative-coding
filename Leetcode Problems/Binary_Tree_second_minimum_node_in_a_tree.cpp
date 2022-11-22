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
    void traverse(TreeNode *root, vector<int> &hold)
    {
        if (root == NULL)
        {
            return;
        }
        hold.push_back(root->val);
        traverse(root->left, hold);
        traverse(root->right, hold);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        vector<int> hold;
        traverse(root, hold);
        sort(hold.begin(), hold.end());
        if (hold.size() == 1 || hold.size() == 0)
        {
            return -1;
        }
        for (int i = 1; i < hold.size(); i++)
        {
            if (hold[i] != hold[i - 1])
            {
                return hold[i];
            }
        }
        return -1;
    }
};