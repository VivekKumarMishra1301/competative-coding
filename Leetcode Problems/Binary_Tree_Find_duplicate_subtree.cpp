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
    //         map<int,vector<TreeNode *>>meraMap;
    //     void traverse(TreeNode *root){
    //         if(root==NULL){
    //             return;
    //         }

    //         meraMap[root->val].push_back(root);
    //         traverse(root->left);
    //         traverse(root->right);
    //     }

    //     bool subtree(TreeNode *root1,TreeNode *root2){
    //         if(root1==NULL&&root2==NULL){
    //             return true;
    //         }
    //         if(root1==NULL||root2==NULL){
    //             return false;
    //         }

    //         if(root1->val!=root2->val){
    //             return false;
    //         }

    //         bool left=subtree(root1->left,root2->left);
    //         bool right=subtree(root1->right,root2->right);
    //         return left||right;

    //     }

    map<string, int> meraMap;

    string traverse(TreeNode *root, vector<TreeNode *> &hold)
    {
        if (root == NULL)
        {
            return "NULL";
        }
        string s = traverse(root->left, hold) + "Left" + traverse(root->right, hold) + "Right" + to_string(root->val);
        meraMap[s]++;
        if (meraMap[s] == 2)
        {
            hold.push_back(root);
        }
        return s;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> hold;
        string s = traverse(root, hold);

        // for(auto i:meraMap){
        //     vector<TreeNode *>check=i.second;
        //     bool flag=false;
        //     for(int i=0;i<check.size()-1;i++){
        //         if(check[i]==root)
        //             continue;
        //         for(int j=i+1;j<check.size();j++){
        //             if(subtree(check[i],check[j])){
        //                 hold.push_back(check[i]);
        //                 flag=true;
        //                 break;
        //             }
        //         }
        //         if(flag){
        //             break;
        //         }
        //     }
        // }
        return hold;
    }
};