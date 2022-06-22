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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int                          left, int right)
    {
        if(left > right) return NULL;
        
        int pivot = left;
        
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        TreeNode* node = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        
        node->left = build(preorder, inorder, rootIdx, left, pivot-1);
        node->right = build(preorder, inorder, rootIdx, pivot+1, right);
        
        return node;        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};