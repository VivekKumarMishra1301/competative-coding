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
    bool traverse(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
        {
            if (root1 == NULL && root2 == NULL)
            {

                return true;
            }
            return false;
        }
        if (root1 != NULL && root2 != NULL)
        {

            if (root1->val != root2->val)
            {
                return false;
            }

            return traverse(root1->left, root2->right) && traverse(root1->right, root2->left);
        }
        else
        {
            return false;
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root->left == NULL && right == NULL)
        {
            return true;
        }

        //         vector<int>hold1;
        //         vector<int>hold2;
        return traverse(root->left, root->right);
        //         traverse(root->right,hold2);

        //         if(hold1==hold2){
        //             return true;
        //         }

        //         return false;
    }
};