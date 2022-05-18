// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
struct Node{
    Node *links[2];
    int value = 0;
    
    bool contains(int bit){
        return (links[bit]!=NULL);
    }
    
    void put(int bit, Node *node){
        links[bit] = node;
    }
    
    Node *get(int bit){
        return links[bit];
    }
};

class Trie{
    private: Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(int num){
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = (num >> i) & 1;
                if(!node->contains(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
            node->value = num;
        }
        
        int maxXor(int num){
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = (num >> i) & 1;
                if(node->contains(1-bit)){
                   node = node->get(1-bit);
                }
                else if(node->contains(bit)){
                    node = node->get(bit);
                }
                
            }
            return num^(node->value);
        }
};

class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        Trie trie;
        trie.insert(0);
        int res = 0;
        int prefixXor = 0;
        for(int i=0;i<N;i++){
            prefixXor = prefixXor^arr[i];
            trie.insert(prefixXor);
            res = max(res,trie.maxXor(prefixXor));
        }
        
        return res;
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
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends