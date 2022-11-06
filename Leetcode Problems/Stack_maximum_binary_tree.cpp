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
    TreeNode* buildTree(vector<int>& nums, int st, int end) {

        if (st > end) {
            return NULL;
        }
        if (st == end) {
            TreeNode* newNode = new TreeNode(nums[st]);
            return newNode;
        }
        int maxind = st;
        int max = nums[st];
        for (int i = st;i <= end;i++) {
            if (nums[i] > max) {
                maxind = i;
                max = nums[i];
            }
        }
        TreeNode* newNode = new TreeNode(nums[maxind]);
        newNode->left = buildTree(nums, st, maxind - 1);
        newNode->right = buildTree(nums, maxind + 1, end);
        return newNode;



    }


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }

        return buildTree(nums, 0, nums.size() - 1);
    }
};