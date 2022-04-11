// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    
    bool isPalindrome(string s, int i, int j){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            
            i++;
            j--;
            
        }
        
        return true;
    }
    
    int solve(string s, int i, int j){
        
        if(i>=j) return dp[i][j]=0;
        
        if(isPalindrome(s,i,j)==true){
            return dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mn = INT_MAX;
        
        int left = 0;
        int right = 0;
        
        for(int k=i;k<=j-1;k++){
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = solve(s,i,k);
                dp[i][k] = left;
            }
            
             if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s,k+1,j);
                dp[k+1][j] = right;
            }
            
            int temp = 1+left+right;
            
            mn = min(mn,temp);
        }
        
        return dp[i][j] = mn;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        
        memset(dp,-1,sizeof(dp));
        
        int s = str.length();
        
        return solve(str,0,s-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends