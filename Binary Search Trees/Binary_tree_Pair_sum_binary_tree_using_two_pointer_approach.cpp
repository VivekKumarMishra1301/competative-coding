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
#include <vector>
#include <algorithm>
void traverse(BinaryTreeNode<int> *root, vector<int> &hold)
{
    if (root == NULL)
    {
        return;
    }
    hold.push_back(root->data);
    traverse(root->left, hold);
    traverse(root->right, hold);
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    // Write your code here
    vector<int> hold;
    traverse(root, hold);
    sort(hold.begin(), hold.end());
    int st = 0;
    int end = hold.size() - 1;
    while (st < end)
    {
        int sum1 = hold[st] + hold[end];
        if (sum1 > sum)
        {
            end--;
        }
        else if (sum1 < sum)
        {
            st++;
        }
        else
        {
            int count1 = 0;
            int count2 = 0;
            int i = st;
            int j = end;
            while (hold[st] == hold[i])
            {
                count1++;
                i++;
            }
            while (hold[end] == hold[j])
            {
                count2++;
                j--;
            }
            int total = count1 * count2;
            while (total--)
            {

                cout << hold[st] << " " << hold[end] << endl;
            }

            st = st + count1;
            end = end - count2;
        }
    }
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}