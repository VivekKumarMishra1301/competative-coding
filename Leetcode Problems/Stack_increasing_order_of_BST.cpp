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
    TreeNode* prev = NULL;
    stack<TreeNode*>hold;

    void pushInStack(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        pushInStack(root->right);
        hold.push(root);
        pushInStack(root->left);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        pushInStack(root);
        prev = hold.top();
        TreeNode* ftree = prev;
        prev->left = NULL;
        hold.pop();
        while (!hold.empty()) {
            prev->right = hold.top();
            prev->left = NULL;
            prev = prev->right;
            hold.pop();
        }
        prev->right = NULL;
        prev->left = NULL;
        return ftree;
    }
};