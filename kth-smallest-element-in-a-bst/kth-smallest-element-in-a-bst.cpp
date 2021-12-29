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
    vector<int> v;
    
    void Inorder(TreeNode* root){
        if(!root) return;
        if(!root->right and !root->left){
            v.push_back(root->val);
            return;
        }
        
        Inorder(root->left);
        v.push_back(root->val);
        Inorder(root->right);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        Inorder(root);
        return v[k-1];
    }
};