// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int win(int arr[],vector<vector<int>> &dp,int start, int end){
    if(start>end) return 0;
    
    if(dp[start][end]!=INT_MIN) return dp[start][end];
    
    int a = arr[start] - win(arr,dp,start+1,end);
    int b = arr[end] - win(arr,dp,start,end-1);
    
    dp[start][end] = max(a,b);
    
    return dp[start][end];
}
    bool is1winner(int N,int arr[]) {
        
        // code here
        // return N%2 == 0 ? true : false;
        //poor test cases...
        
        vector<vector<int>> dp(N,vector<int>(N,INT_MIN));
        
        return win(arr,dp,0,N-1) >= 0;
        
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends