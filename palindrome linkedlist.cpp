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
    ListNode* ReverseLinkedList(ListNode* head){
        ListNode *tmp=head->next;
        ListNode *tmp1;
        if(head==NULL||head->next==NULL) return head;
        head->next=NULL;
       
        while(tmp!=NULL){
            tmp1=tmp->next;
            tmp->next=head;
            head=tmp;
            tmp=tmp1;
        }
        return head;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode* slow=head;
        ListNode* fast=head;
     
        while(fast&&fast->next){// 对于所有的直接start->next->next项必须检查这一句。因为有可能fast！=NULL&&fast->next==NULL；此时直接调用语句 fast->next->next将导致runtime eror. 
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tmp;
     if(fast){                  //此俩句必须检查，因为如果是fast==NULL则节点为偶数，执行else语句。若fast->next为空应执行if语句。 
         tmp=ReverseLinkedList(slow->next);
     }
     else{
         tmp=ReverseLinkedList(slow);
     }
        
        
        while(head&&tmp){
            if (head->val!=tmp->val){
              return false;
            }
            head=head->next;
            tmp=tmp->next;
            }
        return true;
        
    }
};