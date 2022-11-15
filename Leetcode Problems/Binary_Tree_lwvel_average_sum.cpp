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

#include<queue>
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>hold;
        queue<TreeNode*>pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        double sum = 0;
        int count = 0;
        while (!pendingNodes.empty()) {
            TreeNode* top = pendingNodes.front();
            pendingNodes.pop();
            if (top == NULL) {

                if (!pendingNodes.empty()) {

                    hold.push_back(sum / count);
                    count = 0;
                    sum = 0;
                    pendingNodes.push(NULL);
                    continue;
                }
                else
                {
                    hold.push_back(sum / count);
                    break;
                }
            }
            else {

                count++;
                sum = sum + top->val;
                if (top->left != NULL) {

                    pendingNodes.push(top->left);
                }
                if (top->right != NULL) {

                    pendingNodes.push(top->right);
                }
            }


        }
        return hold;
    }
};