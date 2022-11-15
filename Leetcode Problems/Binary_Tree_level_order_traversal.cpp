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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>hold;
        if (root == NULL) {
            return hold;
        }
        queue<TreeNode*>pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int>hold1;
        int i = 0;
        int count = 0;
        while (!pendingNodes.empty()) {
            TreeNode* top = pendingNodes.front();
            pendingNodes.pop();
            if (top == NULL) {

                if (!pendingNodes.empty()) {

                    vector<int>hold2;
                    for (int j = 0;j < count;j++) {
                        hold2.push_back(hold1[j]);
                    }

                    hold.push_back(hold2);
                    i = 0;
                    count = 0;
                    pendingNodes.push(NULL);
                    continue;
                }
                else
                {
                    vector<int>hold2;
                    for (int j = 0;j < count;j++) {
                        hold2.push_back(hold1[j]);
                    }
                    hold.push_back(hold2);
                    break;
                }
            }
            else {
                if (i < hold1.size()) {
                    hold1[i++] = top->val;
                    count++;
                }
                else {
                    i++;
                    hold1.push_back(top->val);
                    count++;
                }

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