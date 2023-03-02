/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *temp = head;
        Node *newHead = new Node(head->val);
        Node *temp1 = newHead;
        temp1->next = temp->next;
        temp->next = temp1;
        temp = temp1->next;
        temp1 = temp1->next;
        while (temp != NULL)
        {
            Node *k = new Node(temp->val);
            k->next = temp->next;
            temp->next = k;
            temp = k->next;
            k = k->next;
        }

        temp = head;
        // while(temp!=NULL){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }

        while (temp != NULL)
        {

            Node *curr = temp->next;
            Node *rand = temp->random;
            if (rand == NULL)
            {
                curr->random = NULL;
            }
            else
                curr->random = rand->next;
            temp = curr->next;
        }

        temp = head;
        temp->next = newHead->next;
        temp1 = newHead;
        temp = temp->next;
        while (temp != NULL)
        {
            temp1->next = temp->next;
            temp1 = temp1->next;
            temp->next = temp1->next;
            temp = temp1->next;
        }
        return newHead;
    }
};