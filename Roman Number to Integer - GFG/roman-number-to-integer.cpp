// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  int value(char a){
      if(a=='I'){
          return 1;
      }
      else if(a=='V'){
          return 5;
      }
      else if(a=='X'){
          return 10;
      }
      else if(a=='L'){
          return 50;
      }
      else if(a=='C'){
          return 100;
      }
      else if(a=='D'){
          return 500;
      }
      else if(a=='M'){
          return 1000;
      }
      
      return -1;
  }
    int romanToDecimal(string &str) {
        // code here
        int sum = 0;
        for(int i=0;i<str.length()-1;i++){
            int a = value(str[i]);
            int b = value(str[i+1]);
            if(a>=b){
                sum = sum + value(str[i]);
            }
            else{
                sum = sum - value(str[i]);
            }
        }
        
        sum = sum + value(str[str.length()-1]);
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends