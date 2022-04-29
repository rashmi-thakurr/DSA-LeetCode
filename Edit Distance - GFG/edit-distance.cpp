// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int solve(string a, string b, int m,int n){
      int dp[m+1][n+1];
      for(int i=0;i<m+1;i++){
          for(int j=0;j<n+1;j++){
              if(i==0){
                  dp[i][j]=j;
              }
              else if(j==0){
                  dp[i][j]=i;
              }
          }
      }
      
      for(int i=1;i<m+1;i++){
          for(int j=1;j<n+1;j++){
              if(a[i-1]==b[j-1]){
                  dp[i][j] = dp[i-1][j-1];
              }
              else{
                  dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
              }
          }
      }
      
      return dp[m][n];
  }
    int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        
        return solve(s,t,m,n);
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends