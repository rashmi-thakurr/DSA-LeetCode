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
    int height(TreeNode* root){
        if(!root) return 0;
        int hl=0,hr=0;
        if(root->left) hl = height(root->left);
        if(root->right) hr = height(root->right);
        return 1+max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
       int hl = height(root->left);
       int hr = height(root->right);
        if(abs(hl-hr) > 1) return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};