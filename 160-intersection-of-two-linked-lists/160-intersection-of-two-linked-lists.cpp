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
    int length(ListNode*head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = length(headA);
        int lB = length(headB);
        
        int diff = abs(lA-lB);
        
        if(lA<lB){
            while(diff--){
                headB = headB->next;
            }
        }
        else{
            while(diff--){
                headA=headA->next;
            }
        }
        
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};