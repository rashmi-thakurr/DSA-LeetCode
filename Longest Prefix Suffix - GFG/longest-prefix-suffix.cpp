// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	   int i=0;
	   int j=1;
	   int k=1;
	   int count=0;
	   int n = s.size();
	   
	   while(k<n){
	       i=0;
	       count=0;
	       j=k;
	       while(s[i]!=s[j] and j<n){
	           j++;
	       }
	       
	       while(s[i]==s[j] and j<n){
	           i++;
	           j++;
	           count++;
	       }
	       
	       if(j==n and count>0){
	           return count;
	       }
	       
	       k++;
	   }
	   
	   return count;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends