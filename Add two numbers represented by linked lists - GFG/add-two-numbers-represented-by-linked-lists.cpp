// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head, struct Node* root){
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        Node* t = head->next;
        head->next = root;
        return reverse(t,head);
        
    }
    
    struct Node* reverse_list(struct Node* head){
        if(!head or !head->next) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr;
        
        while(curr){
            next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        if(first==NULL) return second;
        if(second == NULL) return first;
        
        struct Node* p = reverse_list(first);
        
        struct Node* q = reverse_list(second);
      
        Node* head=NULL;
        Node* temp,*prev = NULL;
        
        
        int carry=0;
        int sum = 0;
        while(p or q){
            sum = ( p ? p->data : 0) + ( q ? q->data : 0) + carry;
            carry = (sum>=10) ? 1 : 0;
            sum = sum % 10;
            temp = new Node(sum);
            if(head==NULL){
                head = temp;
            }
            else{
                prev->next = temp;
            }
            
            prev = temp;
           
           if(p){
               p = p->next;
           }
           
           if(q){
               q = q->next;
           }
        }
        
        if(carry>0){
            temp->next = new Node(carry);
        }
        
        return reverse_list(head);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends