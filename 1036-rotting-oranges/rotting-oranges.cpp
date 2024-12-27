class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || (grid[i][j]<count && grid[i][j]>1)){
            return;
        }
        grid[i][j]=count;
        dfs(grid,i+1,j,count+1);
        dfs(grid,i-1,j,count+1);
        dfs(grid,i,j+1,count+1);
        dfs(grid,i,j-1,count+1);
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int x=0;
        int y=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,2);
                }
            }
        }
        int ans=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
                ans=max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};