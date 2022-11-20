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
    //     int leftsum(TreeNode *root){
    //         if(root==NULL){
    //             return 0;
    //         }

    // if(root->left==NULL&&root->right==NULL){
    //     return root->val;
    // }

    //         return leftsum(root->left);

    //     }

    int sumOfLeftLeaves(TreeNode *root)
    {
        //        if(root->left==NULL&&root->right==NULL){
        //            return 0;
        //        }
        //         int left=leftsum(root->left);
        //         int right=0;
        //         if(root->right!=NULL&&root->right->left!=NULL){

        //          right=leftsum(root->right);
        //         }
        //         return left+right;

        if (root == NULL)
        {
            return 0;
        }
        int left = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            left = root->left->val;
        }
        else
        {

            left = sumOfLeftLeaves(root->left);
        }
        int right = sumOfLeftLeaves(root->right);
        return left + right;
    }
};