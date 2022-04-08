// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        // code here
        // int m = A.size();
        // int n = B.size();
        
        // int dp[m+1][n+1];
        
        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         if(i==0 or j==0){
        //             dp[i][j] = 0;
        //         }
        //     }
        // }
        
        // for(int i=1;i<m+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         if(A[i-1]==B[j-1]){
        //             dp[i][j] = 1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        
        // if(dp[m][n]==A.size()){
        //     return true;
        // }
        
        // return false;
        
        
        int i=0;
        int j=0;
        while(i<A.size() and j<B.size()){
            if(A[i]==B[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            
            
        }
        
        if(i==A.size()){
            return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends