// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
      
       
       priority_queue<long long,vector<long long>,greater<long long>> minh;
       for(long long i=0;i<n;i++){
           minh.push(arr[i]);
       }
       long long cost = 0;
      while(minh.size()>=2){
          long long int first = minh.top();
          minh.pop();
          long long int second = minh.top();
          minh.pop();
          cost = cost + first + second;
          minh.push(first+second);
      }
       return cost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends