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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* tmp=head;
        ListNode* tmp1=head;
        ListNode* tmp2=head;
        while(i<n){
            tmp=tmp->next;
            i++;
        }
        if(!tmp){
            tmp1=tmp1->next;
            delete(head);
            return tmp1;
        }
        while(tmp){
            tmp2=head;
            head=head->next;
            tmp=tmp->next;
            
        }
        tmp2->next=tmp2->next->next;
        delete (head);
        return tmp1;
        
        
    }
};