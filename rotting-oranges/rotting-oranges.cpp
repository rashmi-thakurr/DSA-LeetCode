class Solution {
public:
  
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int time=-1;
        
       queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        if(q.empty()){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1)
                        return -1;
                }
            }
            
            return 0;
        }
           
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                //right
                if(x+1<m and grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                
                //left
                if(x-1>=0 and grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                
                //top
                if(y-1>=0 and grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                
                //down
                if(y+1<n and grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
                
            }
            
            time++;
        }
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return time;
    }
};