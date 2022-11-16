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

    TreeNode* constructTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (is > ie || ps > pe) {
            return NULL;
        }
        // if(is==ie||ps==pe){
        //     TreeNode *newNode=new TreeNode(inorder[is]);
        //     return newNode;
        // }
        TreeNode* newNode = new TreeNode(preorder[ps]);

        int inls = is;
        int k = 0;
        for (int i = 0;i <= ie;i++) {
            if (inorder[i] == preorder[ps]) {
                k = i;
                break;
            }
        }
        int inle = k - 1;
        int irs = k + 1;
        int ire = ie;

        int pls = ps + 1;
        int ple = ps + k - is;
        int prs = ple + 1;
        int pre = pe;
        newNode->left = constructTree(preorder, pls, ple, inorder, inls, inle);
        newNode->right = constructTree(preorder, prs, pre, inorder, irs, ire);
        return newNode;


    }




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ps = 0;
        int pe = preorder.size() - 1;
        int is = 0;
        int ie = inorder.size() - 1;

        return constructTree(preorder, ps, pe, inorder, is, ie);
    }
};