class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r,int c,int min){
        if(r<0 || c<0 || r>grid.size()-1 || c>grid[r].size()-1 || grid[r][c]==0 || (grid[r][c]<min && grid[r][c]>1)){
            return;
        }
        grid[r][c]=min;
        dfs(grid,r-1,c,min+1);
        dfs(grid,r,c+1,min+1);
        dfs(grid,r,c-1,min+1);
        dfs(grid,r+1,c,min+1);
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,2);
                }
            }
        }
        int m=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1)
                return -1;
                m=max(m,grid[i][j]);
            }
        }
        return m-2;
    }
};