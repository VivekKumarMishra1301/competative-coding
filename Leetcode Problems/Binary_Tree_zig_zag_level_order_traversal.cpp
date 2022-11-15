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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>hold;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        if (root == NULL) {
            return hold;
        }
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            vector<int>hold1;
            while (!s1.empty()) {
                TreeNode* top = s1.top();
                s1.pop();
                hold1.push_back(top->val);
                if (top->left != NULL) {
                    s2.push(top->left);
                }
                if (top->right != NULL) {
                    s2.push(top->right);
                }
            }

            vector<int>hold2;
            while (!s2.empty()) {
                TreeNode* top = s2.top();
                s2.pop();
                hold2.push_back(top->val);
                if (top->right != NULL) {
                    s1.push(top->right);
                }
                if (top->left != NULL) {
                    s1.push(top->left);
                }
            }
            if (hold1.size() != 0) {

                hold.push_back(hold1);
            }
            if (hold2.size() != 0) {

                hold.push_back(hold2);
            }


        }
        return hold;

    }
};