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
     
        while(fast&&fast->next){// �������е�ֱ��start->next->next���������һ�䡣��Ϊ�п���fast��=NULL&&fast->next==NULL����ʱֱ�ӵ������ fast->next->next������runtime eror. 
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tmp;
     if(fast){                  //����������飬��Ϊ�����fast==NULL��ڵ�Ϊż����ִ��else��䡣��fast->nextΪ��Ӧִ��if��䡣 
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