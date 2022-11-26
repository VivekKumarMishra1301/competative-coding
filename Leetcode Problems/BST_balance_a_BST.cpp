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
    TreeNode *constructTree(vector<int> &nums, int st, int end)
    {
        if (st > end)
        {
            return NULL;
        }
        if (st == end)
        {
            TreeNode *newNode = new TreeNode(nums[st]);
            return newNode;
        }

        int minind = (st + end) / 2;

        TreeNode *newNode = new TreeNode(nums[minind]);
        newNode->left = constructTree(nums, st, minind - 1);
        newNode->right = constructTree(nums, minind + 1, end);
        return newNode;
    }

    void traverse(TreeNode *root, vector<int> &hold)
    {
        if (root == NULL)
        {
            return;
        }

        traverse(root->left, hold);
        hold.push_back(root->val);
        traverse(root->right, hold);
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> hold;
        traverse(root, hold);
        if (hold.size() == 1)
        {
            TreeNode *newNode = new TreeNode(hold[0]);
            return newNode;
        }

        return constructTree(hold, 0, hold.size() - 1);
    }
};