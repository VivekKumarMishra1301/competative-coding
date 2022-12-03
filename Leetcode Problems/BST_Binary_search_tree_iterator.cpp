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
class BSTIterator
{
public:
    // TreeNode *root;
    stack<TreeNode *> hold;

    BSTIterator(TreeNode *root)
    {
        holdall(root);
    }

    int next()
    {
        TreeNode *top = hold.top();
        hold.pop();
        holdall(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return hold.size() != 0;
    }

private:
    void holdall(TreeNode *root)
    {
        while (root != NULL)
        {
            hold.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */