// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    
    // int fact(int a){
    //     long long int m = 1000000007;
    //     int dp[a+1];
    //     memset(dp,-1,sizeof(dp));
    //     dp[0]=1;
    //     dp[1]=1;
        
    //     for(int i=2;i<a+1;i++){
    //         dp[i] = (i*dp[i-1]%m)%m;
    //     }
        
    //     return dp[a];
    // }
    vector<long long> factorial(vector<long long> a, int n) {
         long long int m = 1000000007;
        
        
        long long mx = *max_element(a.begin(),a.end());
        
        vector<long long> fact(mx+1,1);
        
        for(long long int i=1;i<mx+1;i++){
            fact[i]=(i*fact[i-1]%m)%m;
        }
        
        for(int i=0;i<n;i++){
            a[i]=fact[a[i]];
        }
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends