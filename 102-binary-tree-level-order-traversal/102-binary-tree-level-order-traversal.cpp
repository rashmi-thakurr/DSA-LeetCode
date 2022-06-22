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
   // void solve(TreeNode* root, int level, map<int,vector<int>> &mp){
   //     if(!root) return;
   //     mp[level].push_back(root->val);
   //     if(root->left) solve(root->left, level+1, mp);
   //     if(root->right) solve(root->right, level+1, mp);
   // }
    vector<vector<int>> levelOrder(TreeNode* root) {
      
       // vector<vector<int>> ans;
       //  map<int,vector<int>> mp;
       //  solve(root,0,mp);
       //  for(auto i:mp){
       //      ans.push_back(i.second);
       //  }
       //  return ans;
        vector<vector<int>> ans;
        if(!root) return {};
        if(!root->left and !root->right) return {{root->val}};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            for(int i=0;i<sz;i++){
                TreeNode* p = q.front();
                q.pop();
                v.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};