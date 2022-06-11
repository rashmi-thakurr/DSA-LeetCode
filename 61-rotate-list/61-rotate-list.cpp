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
int length(ListNode * s)
{
    int len=0;
    
    while(s)
    {
        len++;
        s=s->next;
    }
    return len;
}


    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head or !head->next) return head;
     
       int l = length(head);
        k = k%l;
        
        if(k==0) return head;
        
        int cnt = l-k;
        
        ListNode* p = NULL;
        ListNode* q = head;
        
        while(cnt--){
          p=q;
          q=q->next;
        }
        
        p->next = NULL;
        
        ListNode* newhead = q;
        while(q->next){
            q=q->next;
        }
        q->next = head;
        head = newhead;
        
        return head;
 
    }
};