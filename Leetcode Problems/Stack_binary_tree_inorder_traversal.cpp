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
        traverse(root->left, hold);
        hold.push_back(root->val);
        traverse(root->right, hold);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>hold;
        if (root == NULL) {
            return hold;
        }
        traverse(root, hold);
        return hold;
    }
};



//Stack approach for the same problem as stack

vector<int> v;
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    while (root || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
    }
    return v;
}