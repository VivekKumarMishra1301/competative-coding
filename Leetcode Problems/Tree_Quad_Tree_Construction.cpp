/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    bool checkallone(vector<vector<int>> &grid, int x, int y, int len)
    {
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
            {
                if (grid[i][j] != grid[x][y])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Node *construct(vector<vector<int>> &grid, int x, int y, int len)
    {
        if (checkallone(grid, x, y, len))
        {
            Node *newNode = new Node(grid[x][y], true);
            return newNode;
        }

        Node *newNode = new Node(false, false);
        newNode->topLeft = construct(grid, x, y, len / 2);
        newNode->topRight = construct(grid, x, y + len / 2, len / 2);
        newNode->bottomLeft = construct(grid, x + len / 2, y, len / 2);
        newNode->bottomRight = construct(grid, x + len / 2, y + len / 2, len / 2);
        return newNode;
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return construct(grid, 0, 0, grid.size());
    }
};