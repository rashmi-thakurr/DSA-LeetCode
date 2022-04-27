// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
       int len=0;
       int start = 0;
       int end = 0;
       int ctr=0;
       
       for(int i=0;i<n;i++){
           if(arr[i]==1){
               end++;
           }
           else{
               if(ctr<m){
                   ctr++;
                   end++;
               }
               else{
                   while(arr[start]!=0){
                       start++;
                   }
                   start++;
                   end++;
               }
           }
           len = max(len,end-start);
       }
       return len;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends