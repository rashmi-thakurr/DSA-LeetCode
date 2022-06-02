// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.length()/2;
        
        string firstHalf = N.substr(0, n);
        string prevFirstHalf = firstHalf;
        
         next_permutation(firstHalf.begin(), firstHalf.end());
        
        if(firstHalf <= prevFirstHalf)
        {
            return "-1";
        }
        
        string ans;
        ans += firstHalf;
       
        string rans = ans;
        reverse(rans.begin(),rans.end());
        
        
        if(N.length()%2!=0){
            ans += N[n+1/2];
        }
        
        ans += rans;
        // cout<<ans<<endl;
        if(ans > N) return ans;
        
        return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends