// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        vector<long long> left(n);
        vector<long long> right(n);
        long long area=0;
       for(long long int i=0;i<n;i++){
           while(!s.empty() && arr[s.top()]>=arr[i]){
               s.pop();
           }
           
           s.empty() ? left[i]=0 : left[i]=s.top()+1;
           
           s.push(i);
       }
    //   while(!s.empty()){
    //       s.pop();
    //   }
      stack<long long> st;
       for(long long int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
           }
           
           st.empty() ? right[i]=n-1 : right[i]=st.top()-1;
           
           st.push(i);
       }
       
       for(long long int i=0;i<n;i++){
           area = max(area, (right[i]-left[i]+1)*arr[i]);
       }
       
       return area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends