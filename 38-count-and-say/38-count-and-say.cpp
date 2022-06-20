class Solution {
public:
    string countandsay(string s){
        int i=0;
        string temp="";
        while(i<s.length()){
            int cnt=1;
            while(s[i]==s[i+1]){
                cnt++;
                i++;
            }
            temp += to_string(cnt);
            temp += s[i];
            i++;
        }
        return temp;
    }
    string countAndSay(int n) {
      
        if(n==1) return "1";
       
        return countandsay(countAndSay(n-1));
    }
};