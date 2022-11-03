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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode* curr1 = list1;
        // ListNode *currnext1=curr1->next;
        ListNode* curr2 = list2;
        ListNode* start = NULL;
        ListNode* move = NULL;
        // ListNode *currnext2=curr2->next;
        while (curr1 != NULL && curr2 != NULL) {
            if (curr1->val < curr2->val) {
                if (start == NULL) {
                    start = curr1;
                    move = curr1;
                    curr1 = curr1->next;
                }
                else {
                    move->next = curr1;
                    move = move->next;
                    curr1 = curr1->next;
                }
            }
            else if (curr2->val < curr1->val) {
                if (start == NULL) {
                    start = curr2;
                    move = curr2;
                    curr2 = curr2->next;
                }
                else {
                    move->next = curr2;
                    move = move->next;
                    curr2 = curr2->next;
                }
            }
            else {
                if (start == NULL) {
                    start = curr2;
                    move = curr2;
                    curr2 = curr2->next;
                    move->next = curr1;
                    move = move->next;
                    curr1 = curr1->next;

                }
                else {
                    move->next = curr2;
                    move = move->next;
                    curr2 = curr2->next;
                    move->next = curr1;
                    move = move->next;
                    curr1 = curr1->next;
                }
            }
        }

        while (curr1 != NULL) {
            move->next = curr1;
            move = move->next;
            curr1 = curr1->next;
        }
        while (curr2 != NULL) {
            move->next = curr2;
            move = move->next;
            curr2 = curr2->next;
        }
        move->next = NULL;
        return start;
    }
};