/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(!root->left and !root->right) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* p1 = q.front();
                q.pop();
                Node* p2 = (i==n-1) ? NULL : q.front();
                
                p1->next = p2;
                
                if(p1->left) q.push(p1->left);
                if(p1->right) q.push(p1->right);
            }
        }
        
        return root;
    }
};