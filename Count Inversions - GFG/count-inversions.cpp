// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
  //  In merge process, let i is used for indexing left 
  //sub-array and j for right sub-array. At any step in merge(), 
  //if a[i] is greater than a[j], then there are (mid – i) inversions. 
  //because left and right subarrays are sorted, so all the remaining elements 
  //in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

long long merge(long long arr[], long long start, long long mid, long long end){
    long long inv = 0;
    long long n1 = mid-start+1;
    long long n2 = end - mid;
    long long a[n1];
    long long b[n2];
    for(long long int i=0;i<n1;i++){
        a[i] = arr[start+i];
    }
    for(long long int i=0;i<n1;i++){
        b[i] = arr[mid+1+i];
    }
    long long i=0;
    long long j=0;
    long long k=start;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
            inv += (n1-i);
        }
    }
    
    while(i<n1){
        arr[k++] = a[i++];
    }
    
    while(j<n2){
        arr[k++] = b[j++];
    }
    
    return inv;
}    
long long mergeSort(long long arr[], long long start, long long end){
    long long inv = 0;
    if(start<end){
        long long mid = (start + end)/2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid+1, end);
        inv += merge(arr, start, mid, end);
    }
    return inv;
}

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int iC = mergeSort(arr,0,N-1);
        return iC;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends