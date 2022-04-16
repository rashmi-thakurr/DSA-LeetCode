// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    struct Node* reverse(struct Node* head1, struct Node* root){
        
        if(head1==NULL || head1->next==NULL)
            return head1;
         
         Node* t = head1->next;
         head1->next = root;
         return reverse(t,head1);
     
    }
    
     Node* reverse_list(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
        
    }
   
   struct Node* findMid(struct Node* head){
       if(!head or !head->next)
        return head;
        
        struct Node* fast = head;
        struct Node* slow = head;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
       
   } 
   
   bool isSame(struct Node* head1, struct Node* head2){
       
       for(; head1 and head2; head1 = head1->next, head2=head2->next){
           if(head1->data!=head2->data){
               return false;
           }
       }
       
       return true;
   }
   
   
    bool isPalindrome(Node *head)
    {
        //Your code here
        int size = 0;
        Node* x = head;
        
        while(x){
            x = x->next;
            size++;
        }
        
        int mid = (size-1)/2;
        
        Node* midptr = head;
        
        while(mid--){
            midptr = midptr->next;
        }
        
        Node* p = midptr->next;
        
        midptr->next = NULL;
        
        p = reverse_list(p);
        
        bool ans = isSame(head,p);
        
        p = reverse_list(p);
        
        midptr->next = p;
        
        return ans;
   
       
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends