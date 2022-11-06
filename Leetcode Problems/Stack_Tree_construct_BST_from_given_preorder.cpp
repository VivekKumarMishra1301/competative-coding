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
    int i = 0;
    TreeNode* buildTree(vector<int>& nums, int limit) {
        if (i == nums.size() || nums[i] > limit) {
            return NULL;
        }
        TreeNode* newNode = new TreeNode(nums[i++]);
        newNode->left = buildTree(nums, newNode->val);
        newNode->right = buildTree(nums, limit);
        return newNode;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return NULL;
        }

        return buildTree(preorder, INT_MAX);
    }
};