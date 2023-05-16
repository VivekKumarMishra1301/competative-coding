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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *ans = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }

    ListNode *findright(ListNode *head, int k)
    {
        ListNode *turtle = head;
        ListNode *hare = head;
        while (--k)
        {
            hare = hare->next;
        }
        // ListNode *first=hare;
        // while(hare->next!=NULL){
        //     turtle=turtle->next;
        //     hare=hare->next;
        // }
        return hare;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        int lt = left;
        ListNode *l = head;
        ListNode *r = head;
        ListNode *tmp = head;
        ListNode *rt = head;
        ListNode *tail = head;
        ListNode *currhead = head;
        if (left == 1)
        {
            rt = findright(head, right);
            tail = rt->next;
            rt->next = NULL;
            currhead = head;
        }
        else
        {
            while (--left)
            {
                tmp = l;
                l = l->next;
            }
            rt = findright(head, right);
            tail = rt->next;
            cout << tmp->val << " " << l->val << " " << rt->val << endl;
            rt->next = NULL;
            currhead = l;
        }
        if (tmp == head && lt == 1)
        {

            tmp = reverse(currhead);
            head = tmp;
        }
        else
        {
            tmp->next = reverse(currhead);
        }
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = tail;
        return head;
    }
};