// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
       stack<int> st;
       int root = INT_MIN;
       
       for(int i=0;i<N;i++){
           if(arr[i] < root) return 0;
           while(!st.empty() and arr[i] > st.top()){
               root = st.top();
               st.pop();
           }
           
           st.push(arr[i]);
       }
       
       return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends