/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool find(TreeNode* root, TreeNode* currNode, int key){
        if(!root) return false;
        if(root->val == key and currNode!=root) return true;
        else if(root->val < key) return find(root->right,currNode,key);
        else return find(root->left,currNode,key);
    }
    
    bool solve(TreeNode* root, TreeNode* currNode, int k){
        if(!currNode) return false;
       
        int t = k - currNode->val;
        bool a = find(root,currNode,t);
       
        bool b = solve(root,currNode->left,k) or  solve(root,currNode->right,k);
       
        return a or b;
    }
  
    bool findTarget(TreeNode* root, int k) {
       return solve(root,root,k);
    }
};