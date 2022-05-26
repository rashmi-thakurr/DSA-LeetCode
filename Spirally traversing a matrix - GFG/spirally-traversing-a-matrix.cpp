// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> v;
        int start_row = 0;
        int start_col = 0;
        int end_row = r-1;
        int end_col = c-1;
        
        while(start_row<end_row and start_col<end_col){
            for(int i=start_col;i<=end_col;i++){
                v.push_back(matrix[start_row][i]);
            }
            
            for(int j=start_row+1;j<=end_row-1;j++){
                v.push_back(matrix[j][end_col]);
            }
            
            for(int i=end_col;i>=start_col;i--){
                v.push_back(matrix[end_row][i]);
            }
            
            for(int j=end_row-1;j>=start_row+1;j--){
                v.push_back(matrix[j][start_col]);
            }
            
            start_row++;
            end_row--;
            start_col++;
            end_col--;
        }
        
       if(start_col != end_col and start_row == end_row){
            for(int i=start_col;i<=end_col;i++){
                v.push_back(matrix[start_row][i]);
            }
       }
       
       if(start_row!= end_row and start_col == end_col){
           for(int j=start_row;j<=end_row;j++){
                v.push_back(matrix[j][end_col]);
            }
       }
       if(start_row == start_col and end_row == end_col and start_row == end_row){
           v.push_back(matrix[start_row][start_col]);
       }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends