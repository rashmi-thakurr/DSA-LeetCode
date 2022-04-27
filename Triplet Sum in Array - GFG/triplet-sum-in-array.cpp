// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        
    //   sort(A,A+n);
      
    //     for(int i=0;i<n;i++){
    //       int k = X - A[i];
    //       int m = i+1;
    //       int p = n-1;
    //       while(m<p){
    //           if((A[m]+A[p])==k){
    //               return true;
    //           }
    //           else if((A[m]+A[p])>k){
    //               p--;
    //           }
    //           else{
    //               m++;
    //           }
    //       }
    //     }
        
    //     return false;
    
   
    
    // for(int i=0;i<n;i++){
    //      unordered_map<int,int> mp;
    //      int sum = X-A[i];
    //      for(int j=i+1;j<n;j++){
    //          mp[A[j]]++;
    //      }
         
    //      for(int j=i+1;j<n;j++){
    //          if(mp[sum-A[j]]==1 and A[j]!=sum/2){
    //              return true;
    //          }
    //          else if(mp[sum-A[j]]>1 and A[j]==sum/2){
    //              return true;
    //          }
    //      }
    // }
    
    // return false;
    sort(A,A+n);
    for(int i=0;i<n;i++){
        int sum = X-A[i];
        int j=i+1;
        int k=n-1;
        while(j<k){
            if(A[j]+A[k]==sum){
                return true;
            }
            else if(A[j]+A[k]<sum){
                j++;
            }
            else{
                k--;
            }
        }
    }
    
    return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends