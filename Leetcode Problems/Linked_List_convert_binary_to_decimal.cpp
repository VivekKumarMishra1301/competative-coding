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
    int power(int x){
        int ans=1;
        for(int i=0;i<x;i++){
            ans=ans*2;
        }
        return ans;
    }
    int deci(ListNode *head,int x){
        if(head->next==NULL){
            return head->val*1;
        }
        int pow=power(x);
        int ans=head->val*pow+deci(head->next,x-1);
        return ans;
        
    }
    
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return deci(head,count);
    }
};