#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;
#include <climits>
class Pair
{
public:
    int min;
    int max;
    bool isBST;
    int height;
};
Pair largest(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.height = 0;
        ans.isBST = true;
        return ans;
    }

    Pair left = largest(root->left);
    Pair right = largest(root->right);

    Pair result;

    if (left.min == INT_MAX && left.max == INT_MIN && right.min == INT_MAX && right.max == INT_MIN)
    {
        result.min = root->data;
        result.max = root->data;
        result.height = 1;
        result.isBST = true;
        return result;
    }

    if (left.isBST == false || right.isBST == false)
    {
        result.isBST = false;
        result.min = left.min;
        result.max = right.max;
        result.height = max(left.height, right.height);
    }
    else
    {
        if (left.max < root->data && right.min >= root->data)
        {
            result.isBST = true;
            result.min = left.min;
            result.max = right.max;
            result.height = 1 + max(left.height, right.height);
        }
        else
        {
            result.isBST = false;
            result.min = left.min;
            result.max = right.max;
            result.height = max(left.height, right.height);
        }
    }

    if (result.min == INT_MAX)
    {
        result.min = root->data;
    }
    if (result.max == INT_MIN)
    {
        result.max = root->data;
    }

    return result;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return 0;
    }
    return largest(root).height;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}