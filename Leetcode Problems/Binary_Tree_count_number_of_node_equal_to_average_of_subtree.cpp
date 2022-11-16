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

class Pair {
public:
    int first = 0;
    int second = 0;
    int third = 0;
};


class Solution {
public:
    Pair count(TreeNode* root) {
        if (root == NULL) {
            Pair ans;
            ans.first = 0;
            ans.second = 0;
            ans.third = 0;
            return ans;
        }

        Pair left = count(root->left);
        Pair right = count(root->right);
        Pair output;
        output.first = left.first + right.first + root->val;
        output.second = left.second + right.second + 1;
        if (output.first / output.second == root->val) {
            output.third = left.third + right.third + 1;
        }
        else {
            output.third = left.third + right.third;
        }
        return output;
    }
    int averageOfSubtree(TreeNode* root) {
        return count(root).third;
    }
};