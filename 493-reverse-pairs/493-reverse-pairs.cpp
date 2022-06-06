class Solution {
public:
    
    int merge(vector<int> &arr, int start, int mid, int end){
        int n1 = mid-start+1;
        int n2 = end - mid;
        
        int arr1[n1];
        int arr2[n2];
        
        for(int i=0;i<n1;i++){
            arr1[i] = arr[start+i];
        }
        
        for(int i=0;i<n2;i++){
            arr2[i] = arr[mid+i+1];
        }
        
        int i=0;
        int j=0;
        int k=0;
        
        int count = 0;
        
        while(i<n1 and j<n2){
            if((long) arr1[i] > (long) 2*arr2[j]){
                count += (n1-i);
                j++;
            }
            else{
                i++;
            }
        }
        
        i=0;
        j=0;
        k = start;
        
        while(i<n1 and j<n2){
            if(arr1[i] <= arr2[j]){
                arr[k++] = arr1[i++];
            }
            else{
                arr[k++] = arr2[j++];
            }
        }
        
        while(i<n1){
            arr[k++] = arr1[i++];
        }
        
        while(j<n2){
            arr[k++] = arr2[j++];
        }
        
        return count;
    }
    
    int mergeSort(vector<int> &nums, int start, int end){
        int count = 0;
       if (start < end){
            int mid = (start + end) / 2;
            count += mergeSort(nums, start, mid);
            count += mergeSort(nums, mid + 1, end);
            count += merge(nums, start, mid, end);
       }
       
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};