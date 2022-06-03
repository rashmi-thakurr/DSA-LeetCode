// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int start = 0;
    int end = 0;
    int ans = INT_MIN;
    int flag = 0;
    unordered_map<char,int> mp;
    while(end<s.length()){
        mp[s[end]]++;
        if(mp.size()==k){
            flag = 1;
            ans = max(ans,end-start+1);
        }
        else{
            while(mp.size()>k){
                mp[s[start]]--;
                if(mp[s[start]]==0){
                    mp.erase(s[start]);
                }
                start++;
            }
        }
        
        end++;
    }
    
    return (flag==0) ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends