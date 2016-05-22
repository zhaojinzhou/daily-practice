/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * tmp;
        ListNode * tmp1;
        if (head==NULL||head->next==NULL)return head;
        tmp=head->next;
        tmp1=head->next->next;
        head->next=NULL;
        if(!tmp1){
            tmp->next=head;
           // head=tmp;
            return tmp;
        }
        while(tmp1!=NULL){
            tmp->next=head;
            head=tmp;
            tmp=tmp1;
            tmp1=tmp1->next;
        }
        tmp->next=head;
       // tmp=tmp1->next;
       // head=tmp1;
        return tmp;
        
        
        
        
    }
};