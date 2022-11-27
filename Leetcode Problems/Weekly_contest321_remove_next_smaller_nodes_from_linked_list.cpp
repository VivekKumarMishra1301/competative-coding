/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *temp = head;
        stack<ListNode *> hold;
        hold.push(temp);
        temp = temp->next;
        while (temp != NULL)
        {
            while (!hold.empty() && temp->val > hold.top()->val)
            {
                hold.pop();
            }
            hold.push(temp);
            temp = temp->next;
        }

        ListNode *newHead = NULL;
        while (!hold.empty())
        {
            ListNode *top = hold.top();
            hold.pop();
            if (newHead == NULL)
            {
                newHead = top;
                top->next = NULL;
            }
            else
            {
                top->next = newHead;
                newHead = top;
            }
        }
        return newHead;
    }
};