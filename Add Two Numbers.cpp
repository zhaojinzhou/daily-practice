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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp=l1;
        ListNode* tmp4;
        int tmp1=0;
        int tmp2=0;
        bool flag=0;
        
        while(l1&&l2){
        tmp2=l1->val;
        l1->val=(l1->val+l2->val+tmp1)%10;    
        tmp1=(tmp2+l2->val+tmp1)/10;
        tmp4=l1;
        l1=l1->next;
        l2=l2->next;
        
        }
        while(l2){
            if(flag==0){
                tmp4->next=l2;
                flag==1;
           }
            tmp2=l2->val;
            l2->val=(tmp2+tmp1)%10;
            tmp1=(tmp2+tmp1)/10;
            tmp4=l2;
            l2=l2->next;
        }
        while(l1){
            tmp2=l1->val;
            l1->val=(tmp1+tmp2)%10;
            tmp1=(tmp1+tmp2)/10;
            tmp4=l1;
            l1=l1->next;
       
        }
        if (tmp1>0){
            ListNode *tmp3=new ListNode(tmp1);
            tmp4->next=tmp3;
           
        }
        return tmp;
        
    }
};