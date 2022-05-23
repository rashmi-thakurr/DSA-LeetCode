// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int arr[], int N, int L, int R) {
        // code here
        int count = N*(N-1)*(N-2)/6;
        sort(arr,arr+N);
        int lc=0;
        int rc=0;
        for(int i=0;i<N-2;i++){
            int start = i+1;
            int end = N-1;
            while(start<end){
                if(arr[i]+arr[start]+arr[end]<=R){
                    lc += (end-start);
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        
        for(int i=0;i<N-2;i++){
            int start = i+1;
            int end = N-1;
            while(start<end){
                if(arr[i]+arr[start]+arr[end]<=L-1){
                    rc += (end-start);
                    start++;
                }
                else{
                    end--;
                }
            }
        }
      
        
        
        return abs(lc-rc);
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends