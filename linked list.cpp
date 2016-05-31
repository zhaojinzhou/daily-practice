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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *tmp;
        while(fast&&fast->next&&slow){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                tmp=head;
                while(tmp!=slow){
                    slow=slow->next;
                    tmp=tmp->next;
                }
                return tmp;
            }
            
        }
        return NULL;
        
    }
};