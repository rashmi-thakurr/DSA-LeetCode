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
    bool isCousins(TreeNode* root, int x, int y) {
        
       queue<pair<TreeNode*, TreeNode*>> q; //node and parent node
        
        q.push({root,NULL});
        
        while(!q.empty()){
            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;
            
            int n = q.size();
            
            for(int i=0;i<n;i++){
                auto [node, parent] = q.front();
                q.pop();
                
                if(node->val==x) xParent = parent;
                if(node->val==y) yParent = parent;
                
                if(node->left) q.push({node->left,node});
                if(node->right) q.push({node->right,node});
                
            }
            
            if(xParent && yParent) return xParent!=yParent;
        }
        
        return false;
    }
};