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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=0,sizeB=0,diff=0;
        ListNode* A=headA,*B=headB,*C=NULL,*D=NULL;
        while(headA){
            sizeA++;
            headA=headA->next;
            
        }
        while(headB){
            sizeB++;
            headB=headB->next;
            
        }
        if(sizeA>sizeB){
            diff=sizeA-sizeB;
            C=A;
            D=B;
           }
           else{
               diff=sizeB-sizeA;
                C=B;
                D=A;
           }
           while(diff>0){
               C=C->next;
               --diff;
           }
           while(C&&D){
               if(C==D)return D;
               C=C->next;
               D=D->next;
               
           }
           
           return NULL;
           
           
           
        
    }
};