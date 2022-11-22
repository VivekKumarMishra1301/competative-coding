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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> hold;
        if (root == NULL)
        {
            return hold;
        }
        stack<TreeNode *> st;
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while (pendingNodes.size() != 0)
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            if (front == NULL)
            {
                if (pendingNodes.empty())
                {
                    break;
                }
                pendingNodes.push(NULL);
                st.push(front);

                continue;
            }

            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            st.push(front);
        }

        while (!st.empty())
        {
            vector<int> hold1;
            while (!st.empty() && st.top() != NULL)
            {
                TreeNode *top = st.top();
                hold1.push_back(top->val);
                st.pop();
            }
            if (!st.empty())
            {

                st.pop();
            }
            hold.push_back(hold1);
        }

        return hold;
    }
};