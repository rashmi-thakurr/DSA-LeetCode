// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void reverse(int arr[], int start,int end){
        int i=start-1;
        int j=end-1;
        
        while(i<=j){
            int x = arr[i];
            arr[i]=arr[j];
            arr[j]=x;
            i++;
            j--;
        }
        
    }
    void rotateArr(int arr[], int d, int n){
        // code here
        if(!d) return;
        d=d%n;
        reverse(arr,1,d);
        reverse(arr,d+1,n);
        reverse(arr,1,n);
        
        
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends