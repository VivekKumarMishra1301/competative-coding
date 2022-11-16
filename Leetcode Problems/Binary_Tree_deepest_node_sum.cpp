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
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));

    }

    int sum(TreeNode* root, int h) {
        if (root == NULL) {
            // if(h==0){
            //     return root->val;
            // }
            return 0;
        }

        if (h == 1) {
            return root->val;
        }

        int left = sum(root->left, h - 1);
        int right = sum(root->right, h - 1);
        return left + right;


    }

    int deepestLeavesSum(TreeNode* root) {
        int h = getHeight(root);

        int get = sum(root, h);
        return get;
    }
};