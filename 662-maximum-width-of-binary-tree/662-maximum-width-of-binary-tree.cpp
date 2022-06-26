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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int left=0,right=0,ans=0;
        while(!q.empty()){
            int sz = q.size();
            int mn = q.front().second;
            for(int i=0;i<sz;i++){
                int cur_id = q.front().second - mn;
                auto node = q.front().first;
                q.pop();
                if(i==0) left = cur_id;
                if(i==sz-1) right = cur_id;
                if(node->left) q.push({node->left,(long long)2*cur_id+1});
                if(node->right) q.push({node->right,(long long)2*cur_id+2});
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};