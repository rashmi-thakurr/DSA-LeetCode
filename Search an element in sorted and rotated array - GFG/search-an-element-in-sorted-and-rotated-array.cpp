// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int K) {
    //code here
    int start=0;
    int end=arr.size()-1;
    int mid = -1;
    
    while(start<=end){
        mid = start + (end-start)/2;
        
        if(arr[mid]==K){
            return mid;
        }
        else if(arr[start]<=arr[mid]){
            if(K>=arr[start] and K<arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else if(arr[mid]<arr[end]){
            if(K>=arr[mid] and K<arr[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    
    return -1;
}