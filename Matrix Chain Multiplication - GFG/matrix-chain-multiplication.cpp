// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int static dp[501][501];
class Solution{
public:


    int solve(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
        int mn = INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            int t = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            
            if(t<mn){
                mn = t;
            }
        }
        
        return dp[i][j] = mn;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
    //     if(N<0){return 0;}
        
        
    //     int dp[N+1][N+1]={0};
        
       
    //       for(int d=1;d<N;d++){
              
    //           for(int i=1;i<N-d;i++){ 
    //               int j = i+d;
    //              dp[i][j] = INT_MAX;
                 
    //             if(j<=i){
    //                 dp[i][j]=0;
    //             }
    //             else{
    //                   for(int k=i;k<=j-1;k++){
    //                     int m = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[j]*arr[k];
    //                     if(m<dp[i][j]){
    //                         dp[i][j] = m;
    //                     }
    //                 }
    //             }
              
    //         }
           
    //     }
        
    //   return dp[1][N-1];
  
       
    memset(dp,-1,sizeof(dp));
    
    return solve(arr,1,N-1);
    }
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends