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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>hold;
        if (root == NULL) {
            return hold;
        }
        queue<Node*>pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int>hold1;
        int count = 0;
        int i = 0;
        while (!pendingNodes.size() == 0) {
            Node* top = pendingNodes.front();
            pendingNodes.pop();
            if (top == NULL) {

                if (!pendingNodes.empty()) {

                    vector<int>hold2;
                    for (int j = 0;j < count;j++) {
                        hold2.push_back(hold1[j]);
                    }

                    hold.push_back(hold2);
                    i = 0;
                    count = 0;
                    pendingNodes.push(NULL);
                    continue;
                }
                else
                {
                    vector<int>hold2;
                    for (int j = 0;j < count;j++) {
                        hold2.push_back(hold1[j]);
                    }
                    hold.push_back(hold2);
                    break;
                }
            }
            else {
                if (i < hold1.size()) {
                    hold1[i++] = top->val;
                    count++;
                }
                else {
                    i++;
                    hold1.push_back(top->val);
                    count++;
                }

                for (int k = 0;k < top->children.size();k++) {
                    pendingNodes.push(top->children[k]);
                }
            }

        }
        return hold;
    }
};