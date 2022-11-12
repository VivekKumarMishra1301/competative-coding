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
void printAtDepth(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    printAtDepth(root->left, k - 1);
    printAtDepth(root->right, k - 1);
}
BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }

    BinaryTreeNode<int> *left = findNode(root->left, node);
    if (left != NULL)
    {
        return left;
    }
    BinaryTreeNode<int> *right = findNode(root->right, node);
    return right;
}

int printNodeAtK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printAtDepth(root, k);
        return 0;
    }

    int ld = printNodeAtK(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printAtDepth(root->right, k - ld - 2);
        }
        return 1 + ld;
    }
    int rd = printNodeAtK(root->right, target, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printAtDepth(root->left, k - rd - 2);
        }
        return 1 + rd;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    // Write your code herez
    BinaryTreeNode<int> *newNode = findNode(root, node);
    int print = printNodeAtK(root, newNode, k);
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}