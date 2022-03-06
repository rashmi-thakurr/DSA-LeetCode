// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    // Code here
	    int whole = numerator/denominator;
	    string ans;
	    ans += to_string(whole);
	    int rem = numerator%denominator;
	    
	    if(rem==0){
	        return ans;
	    }
	    
	    ans += '.';
	    
	    unordered_map<int,int> mp;
	   // string decimal;
	    while(rem){
	        
	        if(mp.find(rem)!=mp.end()){
	            int len = mp[rem];
	            ans.insert(len,"(");
	            ans+=")";
	            return ans;
	        }
	        else{
	            mp.insert(pair<int,int>(rem,ans.length()));
	           int q = (rem*10)/denominator;
	            rem = (rem * 10)%denominator;
	            
	        
	            ans += to_string(q);
	        
	        }
	        
	        
	        
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends