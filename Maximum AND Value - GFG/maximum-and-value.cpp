// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int checkPattern(int pattern, int arr[], int n){
        int count=0;
        for(int i=0;i<n;i++){
            if((pattern&arr[i]) == pattern)
                count++;
        }
        return count;
    }
    int maxAND (int arr[], int N)
    {
        // Your code here
        int res=0;
        int count;
        
        for(int i=16;i>=0;i--){
            count = checkPattern(res|(1<<i),arr,N);
            
            res = (count>=2) ? res|(1<<i) : res;
        }
        
        return res;
       
    }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends