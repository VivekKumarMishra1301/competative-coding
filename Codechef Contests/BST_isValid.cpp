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
//     long int traverse(TreeNode *root){
//         if(root==NULL){
//             return LONG_MIN;
//         }
        
//         return max(root->val,max(traverse(root->left),traverse(root->right)));
//     }
    
//     long int traversem(TreeNode *root){
//         if(root==NULL){
//             return LONG_MAX;
//         }
        
//         return min(root->val,min(traversem(root->left),traversem(root->right)));
//     }\
    
    bool solve(TreeNode *root,long long int mn,long long int mx){
        if(root==NULL){
            return 1;
        }
        
        if(root->val>=mx||root->val<=mn){
            return 0;
        }
        
        return (solve(root->left,mn,root->val)&&solve(root->right,root->val,mx));
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return true;
        }
//        long int max=traverse(root->left);
//         long int min=traversem(root->right);
        
//         if(max<root->val&&min>root->val&&isValidBST(root->left)&&isValidBST(root->right)){
//             return true;
//         }
//         return false;
        return solve(root,LONG_MIN,LONG_MAX);
    }
};