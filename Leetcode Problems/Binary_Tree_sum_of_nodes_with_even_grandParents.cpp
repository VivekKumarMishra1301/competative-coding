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



    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;
        if (root->val % 2 == 0) {
            if (root->left != 0 && root->left->left != NULL) {
                sum = sum + root->left->left->val;
            }

            if (root->left != 0 && root->left->right != NULL) {
                sum = sum + root->left->right->val;
            }
            if (root->right != 0 && root->right->right != NULL) {
                sum = sum + root->right->right->val;
            }
            if (root->right != 0 && root->right->left != NULL) {
                sum = sum + root->right->left->val;
            }


        }

        int left = sumEvenGrandparent(root->left);
        int right = sumEvenGrandparent(root->right);
        return sum + left + right;

    }



};