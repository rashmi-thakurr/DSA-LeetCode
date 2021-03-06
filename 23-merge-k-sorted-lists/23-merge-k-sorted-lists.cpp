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
    ListNode* mergeSortList(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        
        if(head1->val <= head2->val){
            head1->next = mergeSortList(head1->next, head2);
            return head1;
        }
        else{
            head2->next = mergeSortList(head1,head2->next);
            return head2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int i=0;
        int j=lists.size()-1;
        
        while(i!=j){
            lists[i] = mergeSortList(lists[i],lists[j]);
            j--;
        }
        
        return lists[0];
        
    }
};