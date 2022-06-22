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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left){
            flatten(root->right);
            return;
        } 
        TreeNode *p = root->right;
        TreeNode *q = root->left;
        
        while(q->right) q=q->right;
        
        q->right = p;
        
        root->right = root->left;
        
        root->left = nullptr;
        
        flatten(root->right);
    }
};