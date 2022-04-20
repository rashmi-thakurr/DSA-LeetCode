// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        long long int P = 1;
        vector<long long int> v(n,1ll);
        long long int zeroCount = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                P = P*nums[i];
            }
            else if(nums[i]==0){
                zeroCount++;
            }
        }
        
        for(int i=0;i<n;i++){
             if (zeroCount > 1) {
               v[i]=0;
            }
            else if( zeroCount==0){
                long long int x = P/nums[i];
                v[i] = x;
            }
            else if(zeroCount == 1 && nums[i]!=0){
                v[i] = 0;
            }
            else{
                v[i] = P;
            }

        }
        
        return v;
        
        
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends