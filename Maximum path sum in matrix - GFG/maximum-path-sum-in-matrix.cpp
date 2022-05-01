// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        
        dp[0][0] = Matrix[0][0];
        
        int ans = Matrix[0][0];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0) dp[i][j]=Matrix[i][j];
            }
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int mx = dp[i-1][j];
                if(j!=0) mx = max(mx,dp[i-1][j-1]);
                if(j!=N-1) mx = max(mx,dp[i-1][j+1]);
                dp[i][j] = Matrix[i][j] + mx;
                if(i==N-1) ans = max(ans,dp[i][j]);
            }
            
        }
        
      return ans;
    
    // int result = arr[0][0];
    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             int x = (j == 0) ? 0 : arr[i - 1][j - 1];
    //             int y = arr[i - 1][j];
    //             int z = (j == n - 1) ? 0 : arr[i - 1][j + 1];
    //             arr[i][j] += max({ x, y, z });
    //             if (i == n - 1)
    //                 result = max(result, arr[i][j]);
    //         }
    //     }
    //     return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends