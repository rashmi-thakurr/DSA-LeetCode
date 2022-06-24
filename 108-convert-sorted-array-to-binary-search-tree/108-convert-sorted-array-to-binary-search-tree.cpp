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
    
    TreeNode* build(vector<int> &nums, int start, int end){
        if(start>end) return NULL;
        if(start<0) return NULL;
        if(end>nums.size()-1) return NULL;
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, start, mid-1);
        node->right = build(nums, mid+1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return build(nums,0,nums.size()-1);
    }
};