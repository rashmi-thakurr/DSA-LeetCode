// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


struct Node{
    Node *links[2];
    int value = 0;
    
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    
    Node *getNode(int bit){
        return links[bit];
    }
    
    void putBit(int bit, Node *node){
        links[bit] = node;
    }
};

class Trie{
    private : Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insertNum(int num){
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->putBit(bit,new Node());
                }
                node = node->getNode(bit);
            }
            node->value = num;
        }
        
        // void deleteNum(int num){
        //     Node *node = root;
        //     for(int i=31;i>=0;i--){
        //         int bit = (num >> i) & 1;
        //         if(!node->containsKey(bit)){
        //             return;
        //         }
        //         if(node->count > 1){
        //             node->makeNULL(bit);
        //             return;
        //         }
        //         node = node->getNode(bit);
        //     }
        // }
        
        int getMinXor(int num){
            Node *node = root;
            int ans = 0;
            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(node->containsKey(bit)){
                    node = node->getNode(bit);
                }
                else if(node->containsKey(1-bit)){
                    node = node->getNode(1-bit);
                }
            }
            
            return num ^ node->value;
        }
};
class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        //code here
        
        Trie trie;
       trie.insertNum(arr[0]);
       
       int mn = INT_MAX;
       for(int i=1;i<N;i++){
          mn = min(mn, trie.getMinXor(arr[i]));
           trie.insertNum(arr[i]);
       }
       
       return mn;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends