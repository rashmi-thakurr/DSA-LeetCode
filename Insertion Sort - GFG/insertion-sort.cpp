// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int j)
    {
        //code here
        int key = arr[j+1];
        while(j>=0 and arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        int i,key;
        
        for(int i=0;i<n;i++){
            key = arr[i];
            int j = i-1;
            insert(arr,j);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends