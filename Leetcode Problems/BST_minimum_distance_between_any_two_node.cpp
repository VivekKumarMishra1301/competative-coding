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
class Solution
{
public:
    //     int result=INT_MAX;

    //     int traverse(TreeNode * root){
    //         if(root==NULL){
    //             return 0;
    //         }
    //         int left=traverse(root->left);
    //         int right=traverse(root->right);
    //         if(root->right!=NULL){

    //         result=min(result,min(right-root->val,root->val-left));
    //         }
    //         return root->val;
    //     }

    void traverse(TreeNode *root, vector<int> &hold)
    {
        if (root == NULL)
        {
            return;
        }

        hold.push_back(root->val);
        traverse(root->left, hold);
        traverse(root->right, hold);
    }

    int minDiffInBST(TreeNode *root)
    {
        //      if(root==NULL){
        //          return INT_MAX;
        //      }

        //         if(root->left==NULL&&root->right==NULL){
        //             return INT_MAX;
        //         }

        //         int left=minDiffInBST(root->left);
        //         int right=minDiffInBST(root->right);

        //         if(root->left!=NULL){

        //             left=min(left,root->val-root->left->val);

        //         }else{
        //             left=INT_MAX;
        //         }

        //         if(root->right!=NULL){
        //            right=min(right,root->right->val-root->val);
        //         }else{
        //             right=INT_MAX;
        //         }

        //         return min(left,right);
        vector<int> hold;
        traverse(root, hold);
        int min = INT_MAX;
        sort(hold.begin(), hold.end());
        for (int i = 0; i < hold.size(); i++)
        {
            for (int j = i + 1; j < hold.size(); j++)
            {
                if ((hold[j] - hold[i]) < min)
                {
                    min = hold[j] - hold[i];
                }
            }
        }
        return min;
    }
};