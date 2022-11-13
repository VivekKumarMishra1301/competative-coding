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
    int traverse(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return 2 * sum + root->val;
        }
        sum = 2 * sum + root->val;
        return traverse(root->left, sum) + traverse(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return traverse(root, 0);
    }
};