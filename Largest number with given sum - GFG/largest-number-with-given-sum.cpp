// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
       string ans;
       if(sum > 9*n) return "-1";
       int count=0;
       while(sum){
           if(sum>=9){
               ans += to_string(9);
               sum = sum-9;
           }
           else{
               ans += to_string(sum);
               sum=0;
           }
           count++;
       }
       
       while(count<n){
           ans += to_string(0);
           count++;
       }
       
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends