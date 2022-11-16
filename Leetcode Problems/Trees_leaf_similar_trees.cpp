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

    TreeNode* travel(vector<int>& hold, TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* left = travel(hold, root->left);
        TreeNode* right = travel(hold, root->right);
        if (left == NULL && right == NULL) {
            hold.push_back(root->val);
        }
        return root;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>hold1;
        vector<int>hold2;
        TreeNode* get1 = travel(hold1, root1);
        TreeNode* get2 = travel(hold2, root2);

        return hold1 == hold2;
    }
};