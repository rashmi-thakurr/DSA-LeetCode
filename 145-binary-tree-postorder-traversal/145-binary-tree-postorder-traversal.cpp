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
//     void postorder(TreeNode* root, vector<int>&v){
//         if(root==NULL) return;
        
//         postorder(root->left,v);
//         postorder(root->right,v);
//         v.push_back(root->val);

//     }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*> st;
        st.push(root);
        st.push(root);
       while(!st.empty()){
           TreeNode* curr = st.top();
           st.pop();
           if(!st.empty() and st.top()==curr){
                if(curr->right){
                   st.push(curr->right);
                   st.push(curr->right);
               }
               if(curr->left){
                   st.push(curr->left);
                   st.push(curr->left);
               }
            
           }
           else{
               ans.push_back(curr->val);
           }
       }
        return ans;
    }
};