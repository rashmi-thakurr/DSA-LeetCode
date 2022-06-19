class Solution {
public:
    
    void reversefn(string &word,int i, int j){        
        while(i<j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
    }
   
    string reverseWords(string s) {
        int i=0;
        int j = s.length()-1;
        
        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
        }
        s = s.substr(i,j-i+1);
        
        reverse(s.begin(),s.end());
      
        for(int i=0;i<s.length();i++){
            while(s[i]==' ' and s[i-1] ==' '){
                s.erase(i-1,1);
            };
            int l=i;
            while(s[l]!=' ' and l<s.length()){
                l++;
            }
            reversefn(s,i,l-1);
            i=l;
        }
        
        return s;
        
        
    }
};