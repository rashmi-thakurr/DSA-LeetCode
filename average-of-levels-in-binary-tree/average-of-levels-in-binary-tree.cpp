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
    vector<double> averageOfLevels(TreeNode* root) {
        
         vector<double> v;
        
        if(!root) return v;
        if(!root->left and !root->right){
            v.push_back(root->val);
            return v;
        }
        
        queue<TreeNode*> q;
      
        q.push(root);
        
        double sum=0;
        double avg=0;
        
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* p = q.front();
                q.pop();
                
                if(p->left){
                    q.push(p->left);
                }
                
                if(p->right){
                    q.push(p->right);
                }
                
                sum+=p->val;
            }
            
            avg = sum/n;
            sum=0;
            v.push_back(avg);
        }
        
        return v;
    }
};