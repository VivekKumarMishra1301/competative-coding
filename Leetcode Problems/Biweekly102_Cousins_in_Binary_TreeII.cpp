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
    map<int, map<TreeNode *, vector<int>>> meraMap;
    void tr(TreeNode *root, TreeNode *pr, int h)
    {
        if (root == NULL)
        {
            return;
        }
        meraMap[h][pr].push_back(root->val);
        tr(root->left, root, h + 1);
        tr(root->right, root, h + 1);
    }

    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode *nn = new TreeNode(0);
        if (root->left == NULL && root->right == NULL)
        {
            return nn;
        }
        tr(root, NULL, 0);

        for (auto i : meraMap)
        {
            if (i.first == 0)
            {
                root->val = 0;
                continue;
            }
            int rs = 0;
            for (auto j : i.second)
            {
                vector<int> l = j.second;
                for (int m = 0; m < l.size(); m++)
                {
                    rs += l[m];
                }
            }
            for (auto j : i.second)
            {
                int crsum = 0;
                vector<int> l = j.second;
                for (int m = 0; m < l.size(); m++)
                {
                    crsum += l[m];
                }
                int crans = rs - crsum;
                TreeNode *pr = j.first;
                if (pr->left)
                {
                    pr->left->val = crans;
                }
                if (pr->right)
                {
                    pr->right->val = crans;
                }
            }
        }

        return root;
    }
};