// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
    
    void insertHeap(int &x)
    {
        maxH.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        minH.push(maxH.top());
        maxH.pop();
        
        if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return maxH.size()>minH.size() ? maxH.top() : ((double) maxH.top() + minH.top())*0.5 ;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends