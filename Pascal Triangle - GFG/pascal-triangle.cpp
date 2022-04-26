// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    int pascalNumber(int i, int j){
        int dp[j+1][j+1];
        memset(dp,0,sizeof(dp));
        if(i==0 or i==j){
            return 1;
        }
        
        while(j>0){
            return pascalNumber(i,j-1)+pascalNumber(i-1,j-1);
        }
        
    }
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
    //   vector<ll> v;
    //   int j = n-1;
    //   for(int i=0;i<n;i++){
    //       v.push_back(pascalNumber(i,j)%1000000007);
    //   }
    //   return v;
    
    vector<vector<ll>> ans;
    ll m = 1000000007;
    vector<ll> k;
    k.push_back(1);
    ans.push_back(k);
    
    for(int i=1;i<=n;i++){
        vector<ll> v(i,0);
        for(int j=0;j<i;j++){
            if(j==0 or j==i-1){
                v[j] = 1;
            }
            else{
                v[j] = (ans[i-1][j-1]%m + ans[i-1][j]%m)%m;
            }
        }
        
        ans.push_back(v);
    }
    
    return ans[n];
        
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends