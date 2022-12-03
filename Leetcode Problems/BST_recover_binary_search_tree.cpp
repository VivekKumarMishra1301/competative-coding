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
    
    void traverse(TreeNode *root,vector<int>&hold1,vector<TreeNode *>&hold2){
        if(root==NULL){
            return;
        }
        
        traverse(root->left,hold1,hold2);
        hold1.push_back(root->val);
        hold2.push_back(root);
        traverse(root->right,hold1,hold2);
        
        
    }
    
    
    void recoverTree(TreeNode* root) {
        
        vector<int>hold1;
        vector<TreeNode *>hold2;
        
       traverse(root,hold1,hold2);
        sort(hold1.begin(),hold1.end());
        
        for(int i=0;i<hold2.size();i++){
            hold2[i]->val=hold1[i];
        }
    }
};