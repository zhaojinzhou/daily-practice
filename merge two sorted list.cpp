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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head=NULL,*head1=new ListNode(-111111);
        
        if(!l1)return l2;
        if(!l2) return l1;
        
        head=head1;
        
        while(l1&&l2){
            if(l1->val<l2->val) {
                
                head1->next=l1;
                l1=l1->next;
                head1=head1->next;
            }
            else{
                head1->next=l2;
                l2=l2->next;
                head1=head1->next;
                
            }
         
         
         
            
        }
        if(!l1)head1->next=l2;
        else head1->next=l1;
        return head->next;
        
        
        
        
        
    }
};