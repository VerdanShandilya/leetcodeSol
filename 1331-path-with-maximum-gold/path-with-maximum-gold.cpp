class Solution {
public:
    int helper(vector<vector<int>>& grid,int x,int y,vector<vector<int>> &visited){
        if(x>=grid.size() || y>=grid[x].size() || x<0 || y<0 || grid[x][y] == 0 || visited[x][y]==1){
            return 0;
        }
        visited[x][y]=1;
        int down=helper(grid,x+1,y,visited);
        int up=helper(grid,x-1,y,visited);
        int left=helper(grid,x,y-1,visited);
        int right=helper(grid,x,y+1,visited);
        visited[x][y]=0;
        return grid[x][y]+max({down,up,left,right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!=0){
                    vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));
                    ans=max(ans,helper(grid,i,j,visited));
                }
            }
        }
        return ans;
    }
};