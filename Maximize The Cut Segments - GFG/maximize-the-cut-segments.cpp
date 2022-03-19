// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int cuts[3];
    //   sort(cuts,cuts+3);
    cuts[0] = x;
    cuts[1] = y;
    cuts[2] = z;
      
      /*for(int i=0;i<3;i++){
            cout<<cuts[i]<<" ";
        }
        cout<<endl;*/
        
        int dp[4][n+1];
        
        
        
    //     for(int i=0;i<=3;i++){
    //         for(int j=0;j<=n;j++){
    //             dp[i][j] = 0;
    //         }
    //     }
        
    //     for(int j=1;j<=n;j++){
    //         if(j < cuts[0]){
    //             dp[1][j] = 0;
    //         }
            
    //         else if(j==cuts[0]){
    //             dp[1][j] = 1;
    //         }
            
    //         else if(j > cuts[0]){
    //             if(j%cuts[0] == 0){
    //                 dp[1][j] = (j/cuts[0]);
    //             }
    //             else{
    //                 dp[1][j] = 0;
    //             }
    //         }
    //     }
        
    //     for(int i=2;i<=3;i++){
    //         for(int j=1;j<=n;j++){
    //             if(j<cuts[i-1]){
    //                 dp[i][j] = dp[i-1][j];
    //             }
    //             else if(j==cuts[i-1]){
    //                 dp[i][j] = max(1,dp[i-1][j]);
    //             }
    //             else{
    //                 if(dp[i][j-cuts[i-1]]!=0){
    //                       dp[i][j] = max(dp[i-1][j],1+dp[i][j-cuts[i-1]]);
    //                 }
    //                 else{
    //                     dp[i][j] = dp[i-1][j];
    //                 }
                   
    //             }
                  
    //         }
    //     }
        
        
    //  /* for(int i=0;i<4;i++){
    //       for(int j=0;j<=n;j++){
    //           cout<<dp[i][j]<<" ";
    //       }
    //       cout<<endl;
    //   }*/
       
    //   return dp[3][n];
    
    for(int i=0;i<4;i++){
        for(int j=0;j<n+1;j++){
            if(i==0){
                dp[i][j] = INT_MIN;
            }
            
            if(j==0){
                dp[i][j]=0;
            }
            
        }
    }
    
    
    for(int i=1;i<4;i++){
        for(int j=1;j<n+1;j++){
            if(cuts[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],1 + dp[i][j-cuts[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    if(dp[3][n]<0){
        return 0;
    }
    return dp[3][n];
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends