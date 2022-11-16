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

    TreeNode* constructTree(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (is > ie || ps > pe) {
            return NULL;
        }
        // if(is==ie){
        //     TreeNode* newNode = new TreeNode(inorder[is]);
        //     return newNode;
        // }
        TreeNode* newNode = new TreeNode(postorder[pe]);

        int inls = is;
        int k = 0;
        for (int i = 0;i <= ie;i++) {
            if (inorder[i] == postorder[pe]) {
                k = i;
                break;
            }
        }
        int inle = k - 1;
        int irs = k + 1;
        int ire = ie;

        int pls = ps;
        int ple = ps + k - inls - 1;
        int prs = ple + 1;
        int pre = pe - 1;
        newNode->left = constructTree(postorder, pls, ple, inorder, inls, inle);
        newNode->right = constructTree(postorder, prs, pre, inorder, irs, ire);
        return newNode;


    }




    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ps = 0;
        int pe = postorder.size() - 1;
        int is = 0;
        int ie = inorder.size() - 1;

        return constructTree(postorder, ps, pe, inorder, is, ie);
    }
};



//Better Solution
class Solution {
public:
    TreeNode* rec(int l, int r) {
        if (l > r) return NULL;

        int i = 0;
        while (m_inorder[i] != m_postorder[m_curr]) {
            i++;
        }

        m_curr--;
        TreeNode* node = new TreeNode(m_inorder[i]);
        node->right = rec(i + 1, r);
        node->left = rec(l, i - 1);
        return node;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m_postorder = postorder, m_inorder = inorder, m_curr = inorder.size() - 1;
        return rec(0, postorder.size() - 1);
    }

private:
    int m_curr;
    vector<int> m_postorder, m_inorder;
};












