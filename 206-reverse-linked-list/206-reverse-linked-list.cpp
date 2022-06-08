/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head or !head->next) return head;
        ListNode* p = nullptr;
        ListNode* q = head;
        ListNode* r = nullptr;
        
        while(q){
          
            r=p;
            p=q;
            q=q->next;   
            p->next = r;
        }
        
        return p;
    }
};