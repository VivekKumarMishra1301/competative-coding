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
    bool checkTree(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool left = checkTree(root->left);
        bool right = checkTree(root->right);
        if (left == false || right == false) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        else if (root->left == NULL && root->right->val == root->val) {
            return true;
        }
        else if (root->left->val == root->val && root->right == NULL) {
            return true;
        }
        else {
            if (root->val == root->left->val + root->right->val) {
                return true;
            }
            else {
                return false;
            }
        }
        return true;
    }
};