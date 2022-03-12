// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int dp[n];
        long long int m = 1000000007;
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        
        for(long long int i=2;i<n+1;i++){
            dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends