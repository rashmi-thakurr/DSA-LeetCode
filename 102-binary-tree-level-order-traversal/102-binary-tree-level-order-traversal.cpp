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
   void solve(TreeNode* root, int level, map<int,vector<int>> &mp){
       if(!root) return;
       mp[level].push_back(root->val);
       if(root->left) solve(root->left, level+1, mp);
       if(root->right) solve(root->right, level+1, mp);
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
      
       vector<vector<int>> ans;
        map<int,vector<int>> mp;
        solve(root,0,mp);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};