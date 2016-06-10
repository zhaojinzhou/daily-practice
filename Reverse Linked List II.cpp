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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m-n==0) return head;
        ListNode* tmp=head;
        int i=0;
        ListNode* tmp1;
        ListNode* tmp4;
        ListNode* tmp2;
        ListNode* tmp3;
        //case : head reserve.
        if(m>1){
            while(i<m-2){
                head=head->next;
                i++;
            }
            
            tmp1=head;
            head=head->next;
            tmp4=head;
            i++;
            
            tmp2=head->next;
        }
        
        //case : m=1; head reverse;
        else{
            tmp2=head->next;
            tmp1=head;
        }
        
        while(i<n-1){
            tmp3=tmp2->next;
            tmp2->next=head;
            head=tmp2;
            tmp2=tmp3;
            i++;
        }
        if(m>1){
            tmp1->next=head;
            tmp4->next=tmp3;
            
        }
        else{
            tmp1->next=tmp3;
            tmp=head;
        }
        return tmp;
        
    }
};