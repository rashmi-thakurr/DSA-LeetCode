// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        // code here
        sort(A,A+N);
        int ans = INT_MAX;
        
        vector<int> v(N+1,0);
       
        for(int i=1;i<=N;i++){
            v[i] = v[i-1] + A[i-1];
        }
        
        for(int i=0;i<N;i++){
            int idx = upper_bound(A+i+1,A+N,A[i]+K)-A;
            int actual_sum = v[N]-v[idx];
            int req_sum = (N-idx)*(A[i]+K);
            int to_remove = actual_sum-req_sum;
            to_remove+=v[i];
            ans = min(ans,to_remove);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends