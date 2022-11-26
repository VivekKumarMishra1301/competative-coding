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
class FindElements
{
public:
    TreeNode *root = NULL;
    void create(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left != NULL)
        {
            root->left->val = 2 * root->val + 1;
            create(root->left);
        }

        if (root->right != NULL)
        {
            root->right->val = 2 * root->val + 2;
            create(root->right);
        }
    }
    FindElements(TreeNode *root)
    {
        this->root = root;
        root->val = root->val * 2 + 2;
        create(root);
    }

    bool findval(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root->val == val)
        {
            return true;
        }
        return findval(root->left, val) || findval(root->right, val);
    }

    bool find(int target)
    {
        return findval(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */