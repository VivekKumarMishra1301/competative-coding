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
    void traverse(TreeNode* root, string op, vector<string>& hold) {
        if (root == NULL) {
            return;
        }
        op = op + to_string(root->val);
        traverse(root->left, op + "->", hold);
        traverse(root->right, op + "->", hold);
        if (root->left == NULL && root->right == NULL) {
            hold.push_back(op);
        }


    }


    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>hold;
        traverse(root, "", hold);
        return hold;
    }
};