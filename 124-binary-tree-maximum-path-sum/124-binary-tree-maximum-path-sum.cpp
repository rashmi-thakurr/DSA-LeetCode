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
  
    int solve(TreeNode* root, int &maxSum){
        if(!root) return 0;
        int l = max(solve(root->left,maxSum),0);
        int r = max(solve(root->right,maxSum),0);
        maxSum = max(maxSum, root->val+l+r);
        return root->val + max(l,r);
       
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};