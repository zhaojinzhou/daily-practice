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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p=head;
        while(head&&head->val==val){
              ListNode *tmp1=head;
              p=head->next;
              head=head->next;
              delete(tmp1);
        }    
        
        while(head&&head->next){
               
            if(head->next->val==val){
                ListNode *tmp=head->next;
                head->next=head->next->next;
                delete (tmp);
                
            }
            else{
                head=head->next;
            }
            
        }
        
        return p;
    }
};