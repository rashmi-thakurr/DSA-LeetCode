// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
   bool Boggle(int index, int len, string word,int m, int n, int row, int col, vector<vector<char> >& board, vector<bool> vis[]){
    if(index == len){
        return true;
    }
    
    if(row< 0 || row >= m || col < 0 || col >=n){
        return false;
    }
    
    if(vis[row][col] || word[index] != board[row][col]){
        return false;
    }
    
    vis[row][col] = true;
    
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i == 0 && j == 0)
                continue;
            if(Boggle(index+1,len,word,m,n,row+i,col+j,board,vis)){
                return true;
            }
        }
    }
    vis[row][col] = false;
    return false;
}

bool searchWord(string word, vector<vector<char> >& board, int m, int n){
    
    vector<bool> vis[m];
    int i,j;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            vis[i].push_back(false);
        }
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(word[0] == board[i][j]){
                if(Boggle(0,word.length(),word,m,n,i,j,board,vis))
                    return true;
            }
        }
    }
    return false;
}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    int m = board.size();
    int n = board[0].size();
    
    vector<string> res;
    int i,j,k;
    
    for(i=0;i<dictionary.size();i++){
        if(searchWord(dictionary[i],board,m,n)){
            res.push_back(dictionary[i]);
        }
    }
    return res;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends