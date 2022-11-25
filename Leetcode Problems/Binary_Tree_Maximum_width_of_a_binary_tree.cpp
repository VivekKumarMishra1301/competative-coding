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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        queue<pair<TreeNode *, int>> hold;
        hold.push({root, 0});
        int ans = 0;
        while (!hold.empty())
        {
            int size = hold.size();
            int min = hold.front().second;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                int curr = hold.front().second - min;
                TreeNode *node = hold.front().first;
                hold.pop();
                if (i == 0)
                {
                    first = curr;
                }

                if (i == size - 1)
                {
                    last = curr;
                }

                if (node->left != NULL)
                {
                    hold.push({node->left, (long long)curr * 2 + 1});
                }

                if (node->right != NULL)
                {
                    hold.push({node->right, (long long)curr * 2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};