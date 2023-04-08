/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    map<int, Node *> meraMap;

    void dfs(Node *node, vector<bool> &visited)
    {
        // cout<<node->val<<" ";
        if (visited[node->val])
        {
            return;
        }
        Node *nn;
        if (meraMap.find(node->val) == meraMap.end())
        {
            nn = new Node(node->val);
            meraMap[nn->val] = nn;
        }
        else
        {
            nn = meraMap[node->val];
        }
        visited[node->val] = true;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node *n;
            if (meraMap.find(node->neighbors[i]->val) == meraMap.end())
            {
                n = new Node(node->neighbors[i]->val);

                meraMap[n->val] = n;
            }
            else
            {
                n = meraMap[node->neighbors[i]->val];
            }
            nn->neighbors.push_back(n);
            dfs(node->neighbors[i], visited);
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return node;
        }
        Node *newNode = new Node(node->val);
        meraMap[newNode->val] = newNode;
        vector<bool> visited(100, false);
        dfs(node, visited);
        for (auto i : meraMap)
        {
            cout << i.first << ":";
            Node *l = i.second;
            for (int k = 0; k < l->neighbors.size(); k++)
            {
                cout << l->neighbors[k]->val << " ";
            }
            cout << endl;
        }
        return newNode;
    }
};