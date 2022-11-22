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

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> hold;
        traverse(root1, hold);
        traverse(root2, hold);
        sort(hold.begin(), hold.end());
        return hold;
    }
};