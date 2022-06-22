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
       int hL=0, hR=0;
       if(root->left) hL = height(root->left);
       if(root->right) hR = height(root->right);
       return 1+max(hL,hR);
   }
    int diameterOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
        int hL = height(root->left);
        int hR = height(root->right);
        
        int dL = diameterOfBinaryTree(root->left);
        int dR = diameterOfBinaryTree(root->right);
        
        return max(hL+hR, max(dL,dR));
       
    }
};