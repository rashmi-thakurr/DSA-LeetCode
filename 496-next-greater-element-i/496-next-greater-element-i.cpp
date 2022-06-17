class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ans;
        unordered_map<int,int> mp;
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() and nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()) mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        for(auto i:nums1){
            if(mp.find(i)!=mp.end()){
                ans.push_back(mp[i]);
            }
            else ans.push_back(-1);
        }
        
        return ans;
    }
};