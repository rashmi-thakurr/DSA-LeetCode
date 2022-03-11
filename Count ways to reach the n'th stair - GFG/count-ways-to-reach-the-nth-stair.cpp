// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        long long int m = 1000000007;
      int dp[n+1];
      memset(dp,-1,sizeof(dp));
      dp[0]=1;
      dp[1]=1;
      for(int i=2;i<n+1;i++){
          dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
      }
      
      return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends