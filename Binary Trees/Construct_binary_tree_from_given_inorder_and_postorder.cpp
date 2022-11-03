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
};

using namespace std;
BinaryTreeNode<int> *constructTree(int *preorder, int *inorder, int prestart, int instart, int preend, int inend)
{
    if (prestart == preend)
    {
        BinaryTreeNode<int> *node = new BinaryTreeNode<int>(preorder[prestart]);
        return node;
    }
    if (preend < prestart)
    {
        return NULL;
    }

    int lprestart = prestart + 1;
    int linstart = instart;
    int i = instart;
    while (inorder[i] != preorder[prestart])
    {
        i++;
    }
    
    int linend = i - 1;
    int lpreend = lprestart + linend - linstart;
    int rinstart = i + 1;
    int rinend = inend;
    int rprestart = lpreend + 1;
    int rpreend = preend;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[prestart]);
    BinaryTreeNode<int> *left = constructTree(preorder, inorder, lprestart, linstart, lpreend, linend);
    if (preend < prestart)//this condition is optional
    {
        rprestart = prestart + 1;
    }
    BinaryTreeNode<int> *right = constructTree(preorder, inorder, rprestart, rinstart, rpreend, rinend);
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    // Write your code here
    return constructTree(preorder, inorder, 0, 0, preLength - 1, inLength - 1);
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}