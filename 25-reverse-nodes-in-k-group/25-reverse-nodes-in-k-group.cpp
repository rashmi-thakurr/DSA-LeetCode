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
    ListNode* reverse(ListNode* first, ListNode* last){
        // ListNode* k = last->next;
        ListNode* p = nullptr;
        ListNode* q = first;
        ListNode* r = nullptr;
        
       while(q!=last){
           r=p;
           p=q;
           q=q->next;
           p->next = r;
       }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* node = head;
        int x = k;
        while(x--){
            if(!node) return head;
            node = node->next;
        }
        ListNode* newhead = reverse(head,node);
        head->next = reverseKGroup(node,k);
        return newhead;
    }
};