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
    map<int, vector<TreeNode *>> meraMap;
    bool check(TreeNode *root, int h)
    {
        meraMap[h].push_back(root);
        if (root == NULL)
        {
            return true;
        }
        if (!root->left && root->right)
        {
            return false;
        }
        return check(root->left, h + 1) && check(root->right, h + 1);
    }
    bool isCompleteTree(TreeNode *root)
    {
        if (!check(root, 0))
        {
            return false;
        }
        // return true;
        if (!root->left && !root->right)
        {
            return true;
        }
        for (auto i : meraMap)
        {
            if (i.first == 0)
            {
                continue;
            }
            if (i.first == meraMap.size() - 1)
            {
                continue;
            }
            vector<TreeNode *> curr = i.second;
            vector<TreeNode *> temp = meraMap[i.first - 1];
            cout << i.first << " " << temp.size() << endl;
            if (temp.size() != pow(2, i.first - 1))
            {
                return false;
            }
            bool flag = false;
            int k = i.first;
            for (int i = curr.size() - 1; i >= 0; i--)
            {

                if (!curr[i] && flag)
                {
                    return false;
                }
                else if (curr[i])
                {
                    flag = true;
                }
                if (!curr[i] && !flag)
                {
                    meraMap[k].pop_back();
                }
            }
        }
        return true;
    }
};