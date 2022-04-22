// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int start = 0;
        long long int end = x;
        
        long long int mid = 0;
        long long ans = 0;
        
        while(start<=end){
          mid = start + (end-start)/2;
          long long int k = mid*mid;
          if(k==x){
              return mid;
          }
          else if(k<x){
              start = mid+1;
              ans=mid;
          }
          else{
              end = mid-1;
              
          }
        }
        
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends