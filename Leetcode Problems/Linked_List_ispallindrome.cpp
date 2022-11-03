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
    // ListNode *reverseList(ListNode *head){
    //     if(head==NULL||head->next==NULL){
    //         return head;
    //     }
    //     ListNode *ans=reverseList(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //     return ans;
    // }
        ListNode *temp;
    bool ispal(ListNode* head){
        if(head==NULL){
            return true;
        }
            bool ans=ispal(head->next);
        if(ans==false){
            return false;
        }
        if(temp->val==head->val){
            temp=temp->next;
            return true;
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        
        temp=head;
        return ispal(head);
       
        
        
    }
};