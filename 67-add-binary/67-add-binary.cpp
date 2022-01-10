class Solution {
public:
    int BASE = 2;
    
    string addBinary(string a, string b) {
       int i=a.length()-1,j=b.length()-1,carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry==1){
            carry+=i>=0?a[i--]-'0':0;
            carry+=j>=0?b[j--]-'0':0;
            ans=char(carry%BASE+'0')+ans;
            carry/=BASE;
        }
        return ans;
    }
};