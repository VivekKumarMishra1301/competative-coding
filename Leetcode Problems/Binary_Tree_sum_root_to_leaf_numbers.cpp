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
    void traverse(TreeNode *root, vector<string> &hold, string num)
    {
        if (root == NULL)
        {
            return;
        }

        num = num + to_string(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            hold.push_back(num);
            return;
        }

        traverse(root->left, hold, num);
        traverse(root->right, hold, num);
    }

    int sumNumbers(TreeNode *root)
    {
        vector<string> hold;
        traverse(root, hold, "");
        int sum = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            sum = sum + stoi(hold[i]);
        }
        return sum;
    }
};