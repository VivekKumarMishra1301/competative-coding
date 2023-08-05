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
    vector<TreeNode *> construct(int l, int r)
    {
        if (l > r || l < 1)
        {
            vector<TreeNode *> ans;
            ans.push_back(NULL);
            return ans;
        }

        if (l == r)
        {
            vector<TreeNode *> ans;
            TreeNode *nn = new TreeNode(l);
            ans.push_back(nn);
            return ans;
        }
        vector<TreeNode *> ans;
        for (int i = l; i <= r; i++)
        {
            vector<TreeNode *> left = construct(l, i - 1);
            vector<TreeNode *> right = construct(i + 1, r);
            for (int k = 0; k < left.size(); k++)
            {
                for (int j = 0; j < right.size(); j++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[k];
                    root->right = right[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return construct(1, n);
    }
};