// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
       priority_queue<pair<int,int>> minH;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
       for(auto it=mp.begin();it!=mp.end();it++){
           minH.push({it->second,it->first});
       }
       
       while(k--){
           ans.push_back(minH.top().second);
           minH.pop();
       }
       
       
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends