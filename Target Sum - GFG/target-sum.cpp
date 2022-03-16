// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int count(vector<int> arr,int N, int sum){
      int dp[N+1][sum+1];
      
      for(int i=0;i<N+1;i++){
          for(int j=0;j<sum+1;j++){
              if(i==0){
                  dp[i][j]=0;
              }
              if(j==0){
                  dp[i][j]=1;
              }
          }
      }
      
      for(int i=1;i<N+1;i++){
          for(int j=1;j<sum+1;j++){
              if(arr[i-1]<=j){
                  dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
              }
              else{
                  dp[i][j] = dp[i-1][j];
              }
          }
      }
      
      return dp[N][sum];
  }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum += A[i];
        }
        
        if((target + sum)%2!=0){
            return 0;
        }
        int new_sum = (target + sum)/2;
        return count(A,A.size(),new_sum);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends