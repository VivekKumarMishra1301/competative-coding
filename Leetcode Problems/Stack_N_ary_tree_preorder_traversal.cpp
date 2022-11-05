/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    stack<Node*>get;

    void traverse(Node* root) {
        if (root == NULL) {
            return;
        }

        for (int i = root->children.size() - 1;i >= 0;i--) {


            traverse(root->children[i]);
        }
        get.push(root);


    }

    vector<int> preorder(Node* root) {
        vector<int>hold;
        if (root == NULL) {
            return hold;
        }
        traverse(root);
        while (!get.empty()) {
            hold.push_back(get.top()->val);
            get.pop();
        }
        return hold;
    }
};
