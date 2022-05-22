// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
   void solve(int a[],int n,int index,vector<string>&ans,string out,string map[])
    {
        if(index>=n)
        {
            ans.push_back(out);
            return ;
        }
        int number=a[index];
        string value= map[number];
        for(int i=0;i<value.length();i++)
        {
            out.push_back(value[i]);
            solve(a,n,index+1,ans,out,map);
            out.pop_back();
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string out;
        vector<string>ans;
        int index=0;
        solve(a,n,index,ans,out,map);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends