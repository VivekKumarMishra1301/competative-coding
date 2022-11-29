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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> hold;
        if (root == NULL)
        {
            return hold;
        }
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        int maxi = INT_MIN;
        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            if (front == NULL)
            {
                if (pendingNodes.empty())
                {
                    hold.push_back(maxi);
                    return hold;
                }
                hold.push_back(maxi);
                maxi = INT_MIN;
                pendingNodes.push(NULL);
                continue;
            }
            maxi = max(front->val, maxi);
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
        return hold;
    }
};