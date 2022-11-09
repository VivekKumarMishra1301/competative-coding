#include <iostream>
using namespace std;

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

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/
    int findMin(BinaryTreeNode<int> *node)
    {
        if (node->left->left == NULL)
        {
            int result = node->left->left->data;
            node->left = NULL;
            return result;
        }
        return findMin(node->left);
    }

    BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *node, int data)
    {

        if (node == NULL)
        {
            return NULL;
        }

        if (node->data == data)
        {
            if (node->left == NULL && node->right == NULL)
            {
                return NULL;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                return node->left;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                return node->right;
            }
            else
            {
                if (node->right->left == NULL)
                {
                    node->data = node->right->data;
                    node->right = NULL;
                }
                else
                {

                    node->data = findMin(node->right);
                }
            }
        }
        else if (node->data > data)
        {
            node->left = deleteNode(node->left, data);
        }
        else
        {
            node->right = deleteNode(node->right, data);
        }
        return node;
    }

    void remove(int data)
    {
        // Implement the remove() function
        root = deleteNode(root, data);
    }

    void PrintNode(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L"
                 << ":" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R"
                 << ":" << node->right->data << endl;
        }
        else
        {

            cout << endl;
        }

        PrintNode(node->left);
        PrintNode(node->right);
    }

    void print()
    {
        // Implement the print() function
        PrintNode(root);
    }

    BinaryTreeNode<int> *construct(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newRoot = new BinaryTreeNode<int>(data);
            return newRoot;
        }
        if (node->data >= data)
        {
            node->left = construct(node->left, data);
        }
        else
        {
            node->right = construct(node->right, data);
        }
        return node;
    }

    void insert(int data)
    {
        // Implement the insert() function
        root = construct(root, data);
    }

    bool find(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return find(node->left, data);
        }
        else
        {
            return find(node->right, data);
        }
    }

    bool search(int data)
    {
        // Implement the search() function
        return find(root, data);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}