// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  string common(string a, string b){
      string ans = "";
      for(int i=0;i<a.length();i++){
          if(a[i]==b[i]){
              ans += a[i];
          }
          else{
              break;
          }
      }
      
      if(ans == "") return "-1";
      
      return ans;
  }
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = arr[0];
        for(int i=1;i<N;i++){
            ans = common(ans,arr[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends