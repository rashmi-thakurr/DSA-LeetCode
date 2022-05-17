// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
struct Node{
    Node *links[26];
    int value = 0;
    
    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }
    
    void put(char ch,Node *node){
        links[ch - 'a'] = node;
    }
    
    Node *get(char ch){
        return links[ch - 'a'];
    }
    
    bool isEnd(){
        return value;
    }
    
};
class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insertString(string key){
            Node *node = root;
            int n = key.length();
            for(int i=0;i<n;i++){
                if(!node->containsKey(key[i])){
                    node->put(key[i],new Node());
                }
                node = node->get(key[i]);
            }
            
            node->value++;
        }
        
        int getCountOfString(string key){
            Node* node = root;
            int n = key.length();
            for(int i=0;i<n;i++){
                if(!node->containsKey(key[i])){
                    return 0;
                }
                node = node->get(key[i]);
            }
            
            return node->value;
        }
        
        
};
class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insertString(arr[i]);
        }
        
        int mx = -1;
        string freq = arr[0];
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            if(trie.getCountOfString(arr[i]) >= mx and mp.find(arr[i])==mp.end()){
                mx = trie.getCountOfString(arr[i]);
                freq = arr[i];
                mp[arr[i]]++;
            }
        }
        
        return freq;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends