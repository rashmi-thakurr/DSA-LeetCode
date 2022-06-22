/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isPresent(TreeNode* root, TreeNode* p){
        if(!root) return false;
        if(root==p) return true;
        return isPresent(root->left,p) or isPresent(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isPresent(root->left,p) and isPresent(root->left,q))
            return lowestCommonAncestor(root->left,p,q);
        else if(isPresent(root->right,p) and isPresent(root->right,q))
            return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};