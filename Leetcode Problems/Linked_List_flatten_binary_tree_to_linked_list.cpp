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
    //     TreeNode *flatten2(TreeNode *root){
    //         if(root==NULL){
    //             return root;
    //         }
    //         TreeNode *left=flatten2(root->left);
    //         TreeNode *right=flatten2(root->right);
    //             TreeNode *temp=root->right;
    //         if(left!=NULL){
    //             root->right=left;
    //         }

    //         if(root->right!=NULL){
    //             while(temp->right!=NULL){
    //                 temp=temp->right;
    //             }
    //             temp->right=right;
    //         }
    //         return root;
    //     }
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};