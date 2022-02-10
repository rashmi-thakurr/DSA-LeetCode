class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> umap;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            int x = nums2[i];
            while(!st.empty() and st.top()<=x){
                st.pop();
            }
            if(!st.empty()){
                umap[x]=st.top();
            }
            st.push(x);
        }
        
        for(auto num:nums1){
            if(umap.count(num)){
                v.push_back(umap[num]);
            }else{
                v.push_back(-1);
            }
        }
        
        return v;
    }
};