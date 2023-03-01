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
    map<pair<int, int>, vector<int>> meraMap;
    void traverse(TreeNode *root, int dir, int depth)
    {
        if (root == NULL)
        {
            return;
        }

        meraMap[{dir, depth}].push_back(root->val);
        traverse(root->left, dir - 1, depth + 1);
        traverse(root->right, dir + 1, depth + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> hold;
        traverse(root, 0, 0);
        map<int, vector<int>> mp;
        for (auto i : meraMap)
        {
            cout << i.first.first << i.first.second << ":" << endl;
            sort(i.second.begin(), i.second.end());
            for (int k = 0; k < i.second.size(); k++)
            {
                cout << i.second[k] << " ";
                mp[i.first.first].push_back(i.second[k]);
            }
            cout << endl;
        }

        // for(auto i:meraMap){
        //     vector<int>k=i.second;
        //     for(int l=0;l<k.size();l++){
        //         mp[i.first.first].push_back(k[l]);
        //     }
        // }
        for (auto i : mp)
        {
            hold.push_back(i.second);
        }
        return hold;
    }
};