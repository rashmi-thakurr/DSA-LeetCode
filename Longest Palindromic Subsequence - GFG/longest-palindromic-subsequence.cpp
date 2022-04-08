// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(),B.end());
        int m = A.size();
        int dp[m+1][m+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][m];
        
        
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends