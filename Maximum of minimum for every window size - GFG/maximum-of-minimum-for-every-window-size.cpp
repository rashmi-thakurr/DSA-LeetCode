// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int> st;
        vector<int> v(n+1,0);
        vector<int> left(n);
        vector<int> right(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int length = right[i] - left[i] -1;
            
            v[length] = max(v[length], arr[i]);
        }
        
        for(int i=n-1;i>=1;i--){
            v[i] = max(v[i],v[i+1]);
        }
        
        vector<int> ans(n);
        
        for(int i=1;i<=n;i++){
            ans[i-1] = v[i];
        }
        
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends