// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* midNode(Node* head){
        if(!head or !head->next){
            return head;
        }
        
        Node* fast = head->next;
        Node* slow = head;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    
    Node* merge(Node* left, Node* right){
        if(!left and !right) return NULL;
        if(!left and right) return right;
        if(left and !right) return left;
        
        if(!left->next and !right->next){
            if(left->data <= right->data){
                left->next = right;
                return left;
            }
            else{
                right->next = left;
                return right;
            }
        }
        
        if(left->data <= right->data){
            left->next = merge(left->next,right);
            return left;
        }
        else{
            right->next = merge(left,right->next);
            return right;
        }
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next)
            return head;
            
        Node* mid = midNode(head);
        
        Node* right = mid->next;
        mid->next = NULL;
        Node* left = head;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left,right);
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends