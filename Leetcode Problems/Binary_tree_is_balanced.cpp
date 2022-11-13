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
    
    pair<int,bool> check(TreeNode* root){
        if(root==NULL){
            pair<int,bool>ans;
            ans.first=0;
            ans.second=true;
            return ans;
        }
        
        pair<int,bool>ans1=check(root->left);
        pair<int,bool>ans2=check(root->right);
        pair<int,bool>ans;
        ans.first=1+max(ans1.first,ans2.first);
        if(!ans1.second||!ans2.second||abs(ans1.first-ans2.first)>1){
            ans.second=false;
        }else{
            ans.second=true;
        }
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root).second;
    }
};