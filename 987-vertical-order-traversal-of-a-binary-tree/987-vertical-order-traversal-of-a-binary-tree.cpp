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
    void solve(TreeNode* root, map<int,vector<pair<int,int>>>&mp, int level, int hd){
        if(!root) return;
        mp[hd].push_back({root->val,level});
        if(root->left) solve(root->left,mp,level+1,hd-1);
        if(root->right) solve(root->right,mp,level+1,hd+1);
    }
    bool static comp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second) return a.first<b.first;
        return a.second<b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>>mp;
        solve(root,mp,0,0);
        for(auto i:mp){
            sort(i.second.begin(),i.second.end(),comp);
            vector<int> v;
            for(auto j:i.second){
                v.push_back(j.first);
            }
            ans.push_back(v);
        }
        return ans;
    }
};