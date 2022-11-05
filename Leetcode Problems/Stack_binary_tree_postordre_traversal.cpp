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

    void   traverse(TreeNode* root, vector<int>& hold) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, hold);
        traverse(root->right, hold);
        hold.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>hold;
        if (root == NULL) {
            return hold;
        }
        traverse(root, hold);
        return hold;
    }
};