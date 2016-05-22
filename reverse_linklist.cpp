class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * tmp;
        ListNode * tmp1;
        if (head==NULL||head->next==NULL)return head;
        tmp=head->next;
        head->next=NULL;
       
        while(tmp!=NULL){
            tmp1=tmp->next;
            tmp->next=head;
            head=tmp;
            tmp=tmp1;
            
        }
        return head;
    }
};