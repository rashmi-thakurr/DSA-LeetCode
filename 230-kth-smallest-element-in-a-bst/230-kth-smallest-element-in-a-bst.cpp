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
    
    int numOfNodes(TreeNode* root){
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        return 1+numOfNodes(root->left)+numOfNodes(root->right);
    }
    
   
    int kthSmallest(TreeNode* root, int k) {
        int num = numOfNodes(root->left);
       if(num == k-1){
           return root->val;
       }
        else if(num > k-1){
            return kthSmallest(root->left,k);
        }
        else if(num < k-1){
            return kthSmallest(root->right,k-num-1);
        }
        return root->val;
    }
};