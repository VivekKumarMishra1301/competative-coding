#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return root;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int> *max = root;
    TreeNode<int> *smax = NULL;
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            TreeNode<int> *child = front->children[i];
            if (child->data > max->data)
            {
                smax = max;
                max = child;
            }
            else if (child->data != max->data && (smax == NULL || child->data > smax->data))
            {
                smax = child;
            }
            pendingNodes.push(child);
        }
    }
    return smax;
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

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}