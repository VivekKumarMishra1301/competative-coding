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
pair<bool, int> check(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }
    pair<bool, int> left = check(root->left);
    pair<bool, int> right = check(root->right);
    pair<bool, int> result;
    if (left.first == false || right.first == false)
    {
        result.first = false;
        result.second = 1 + max(left.second, right.second);
        return result;
    }
    if (abs(left.second - right.second) <= 1)
    {
        result.first = true;
        result.second = 1 + max(left.second, right.second);
        return result;
    }
    else
    {
        result.first = false;
        result.second = 1 + max(left.second, right.second);
        return result;
    }
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    return check(root).first;
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
    cout << (isBalanced(root) ? "true" : "false");
}