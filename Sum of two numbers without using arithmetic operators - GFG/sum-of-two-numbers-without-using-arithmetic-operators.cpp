// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
      if(b==0) return a;
      if(a==0) return b;
       int carry;
       int s;
     while(carry){
         carry = (a&b) << 1;
         s = a^b;
         a = s;
         b = carry;
     }
     
     return s;
    }
    // int sum(int a, int b){
    //     for(int i=0;i<b;i++){
    //         a++;
    //     }
        
    //     return a;
    // }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends