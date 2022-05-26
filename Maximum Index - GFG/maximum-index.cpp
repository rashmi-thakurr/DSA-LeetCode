// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int leftmin[N];
        leftmin[0] = A[0];
        for(int i=1;i<N;i++){
            leftmin[i] = min(leftmin[i-1],A[i]);
        }
        int i=N-1;
        int j=N-1;
        int ans = INT_MIN;
        
        while(i>=0 and j>=0){
            if(A[j]>=leftmin[i]){
                ans = max(ans,j-i);
                i--;
                
            }
            else{
                j--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends