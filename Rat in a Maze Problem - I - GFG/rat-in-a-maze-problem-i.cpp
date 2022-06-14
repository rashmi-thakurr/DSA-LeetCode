// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int n, int i, int j, string str, vector<string> &ans){
      if(i==n-1 and j==n-1){
          ans.push_back(str);
          return;
      }
      
      if(i>0 and m[i-1][j]==1){
          m[i][j] = 0;
          str.push_back('U');
          solve(m,n,i-1,j,str,ans);
          str.pop_back();
          m[i][j]=1;
      }
      
      if(i<n-1 and m[i+1][j]==1){
          m[i][j]=0;
          str.push_back('D');
          solve(m,n,i+1,j,str,ans);
          str.pop_back();
          m[i][j]=1;
      }
      if(j>0 and m[i][j-1]==1){
          m[i][j]=0;
          str.push_back('L');
          solve(m,n,i,j-1,str,ans);
          str.pop_back();
          m[i][j]=1;
      }
      if(j<n-1 and m[i][j+1]==1){
          m[i][j]=0;
          str.push_back('R');
          solve(m,n,i,j+1,str,ans);
          str.pop_back();
          m[i][j]=1;
      }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
      vector<string> ans;
      string str;
      if(m[0][0] == 0){
          ans.push_back("-1");
          return ans;
    }
      solve(m,n,0,0,str,ans);
      return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends