// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
      int ptr1 = 0;
      int ptr2 = 0;
      int count = 0;
      while(ptr1<n and ptr2<m){
          if(arr1[ptr1]<=arr2[ptr2]){
              count++;
              if(count==k) return arr1[ptr1];
              ptr1++;
          }
          else{
              count++;
              if(count==k) return arr2[ptr2];
              ptr2++;
          }
      }
      
      while(ptr1<n){
          count++;
          if(count==k) return arr1[ptr1];
          ptr1++;
      }
      
       while(ptr2<m){
           count++;
            if(count==k) return arr2[ptr2];
          ptr2++;
      }
      
      return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends