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
    ListNode* reverse(ListNode* head){
        if(!head or !head->next) return head;
        
        ListNode* p = nullptr;
        ListNode* q = head;
        ListNode* r = nullptr;
        
        while(q){
            r=p;
            p=q;
            q=q->next;
            p->next=r;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = reverse(slow);
        
        fast = head;
        
        while(fast and slow){
            if(fast->val != slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    }
};