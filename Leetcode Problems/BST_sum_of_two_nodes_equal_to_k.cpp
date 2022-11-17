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

    void traverse(TreeNode* root, vector<int>& hold) {

        if (root == NULL) {
            return;
        }

        hold.push_back(root->val);
        traverse(root->left, hold);
        traverse(root->right, hold);

    }


    bool findTarget(TreeNode* root, int k) {
        vector<int>hold;
        traverse(root, hold);
        sort(hold.begin(), hold.end());
        int st = 0;
        int end = hold.size() - 1;
        while (st < end) {
            int sum = hold[st] + hold[end];
            if (sum > k) {
                end--;
            }
            else if (sum < k) {
                st++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};