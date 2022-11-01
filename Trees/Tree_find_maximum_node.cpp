#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    // Write your code here
    TreeNode<int> *max = root;
    int maxnum = 0;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int> *front = pendingNodes.front();
    // pendingNodes.pop();
    maxnum = front->data;
    max = front;
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // sum=sum+front->data;
        for (int i = 0; i < front->children.size(); i++)
        {
            TreeNode<int> *child = front->children[i];
            pendingNodes.push(child);
            if (child->data > maxnum)
            {
                maxnum = child->data;
                max = child;
            }
        }
    }
    return max;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxDataNode(root);

    if (root != NULL)
    {
        cout << ans->data;
    }
}