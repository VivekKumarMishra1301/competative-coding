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
    unordered_map<int, long long> meraMap;
    void traverse(TreeNode *root, int h)
    {
        if (root == NULL)
        {
            return;
        }
        long long s = meraMap[h];
        s += root->val;
        meraMap[h] = s;
        traverse(root->left, h + 1);
        traverse(root->right, h + 1);
    }
    long long kthLargestLevelSum(TreeNode *root, int k)
    {

        traverse(root, 0);
        priority_queue<long long> pq;
        if (meraMap.size() < k)
        {
            return -1;
        }
        for (auto i : meraMap)
        {

            pq.push(i.second);
        }
        for (int i = 1; i < k; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};