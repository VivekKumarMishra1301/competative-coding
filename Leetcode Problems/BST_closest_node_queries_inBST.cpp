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
    //     int mini;
    //     int maxi;
    //     void findMinMax(TreeNode *root,int val){
    //         if(root==NULL){
    //             return;
    //         }

    //         if(root->val==val){
    //             mini=val;
    //             maxi=val;
    //             return;
    //         } if(root->val<val){
    //              mini=max(mini,root->val);
    //             findMinMax(root->right,val);

    //         }else{
    //              maxi=min(maxi,root->val);
    //             findMinMax(root->left,val);

    //         }

    //     }

    void traverse(TreeNode *root, vector<int> &hold)
    {
        if (root == NULL)
        {
            return;
        }

        traverse(root->left, hold);
        hold.push_back(root->val);
        traverse(root->right, hold);
    }

    int minval(vector<int> &hold, int val)
    {
        int mi = -1;
        int st = 0;
        int end = hold.size() - 1;
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (hold[mid] <= val)
            {
                mi = max(mi, hold[mid]);
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return mi;
    }

    int maxval(vector<int> &hold, int val)
    {
        int ma = INT_MAX;
        int st = 0;
        int end = hold.size() - 1;
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (hold[mid] >= val)
            {
                ma = min(ma, hold[mid]);
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        if (ma == INT_MAX)
        {
            return -1;
        }
        return ma;
    }

    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        //         vector<vector<int>>hold;

        //         for(auto i:queries){
        //                  mini=-1;
        //                  maxi=INT_MAX;
        //             findMinMax(root,i);
        //             if(maxi==INT_MAX){
        //                 maxi=-1;
        //             }
        //             hold.push_back({mini,maxi});
        //         }
        //         return hold;

        vector<int> hold1;
        traverse(root, hold1);
        vector<vector<int>> hold;
        for (auto i : queries)
        {
            int mi = minval(hold1, i);
            int ma = maxval(hold1, i);

            hold.push_back({mi, ma});
        }
        return hold;
    }
};