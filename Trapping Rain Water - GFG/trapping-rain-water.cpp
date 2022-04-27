// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int leftmax[n];
        int rightmax[n];
        long long int ans=0;
        
        leftmax[0] = arr[0];
        rightmax[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],arr[i]);
        }
        
        for(int j=n-2;j>=0;j--){
            rightmax[j]=max(rightmax[j+1],arr[j]);
        }
        
        for(int i=0;i<n;i++){
            ans = ans + (min(leftmax[i],rightmax[i])-arr[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends