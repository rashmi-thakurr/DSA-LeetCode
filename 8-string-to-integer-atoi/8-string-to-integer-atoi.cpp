class Solution {
public:
    string num(string s){
        int i=0;
        string ans="";
        while(s[i]==' ')i++;
        if(s[i]=='+' or s[i]=='-'){
             ans+=s[i];
            i++;
        }
        
        while(s[i]-'0'>=0 and s[i]-'0'<=9){
            ans += s[i];
            i++;
        }
        return ans;
    }
    int myAtoi(string s) {
        long long int ans=0;
        int i=0;
        s = num(s);
        if(s==" ") return 0;
        if (s[0]=='+' or s[0]=='-'){
           i=1;
        }
        
        while(i<s.length()){
            if(ans > INT_MAX/10 or (ans == INT_MAX/10 and s[i]-'0'>7)){
                if(s[0]=='-') return INT_MIN;
                return INT_MAX;
            }
          
            ans = ans*10 + (s[i]-'0');
            i++;
        }
       
        if(s[0]=='-')ans=ans*(-1);
        
        return ans;
    
    }
};