class Solution {
public:
    int helper(vector<vector<int>> &grid,vector<vector<int>> &visited,int x,int y,int cnt,int a){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1 || visited[x][y] == 1) {
            return 0;
        }
        if(grid[x][y]==2 && cnt==a){
            return 1;
        }
        visited[x][y]=1;
        int top=helper(grid,visited,x-1,y,cnt+1,a);
        int right=helper(grid,visited,x,y+1,cnt+1,a);
        int left=helper(grid,visited,x,y-1,cnt+1,a);
        int down=helper(grid,visited,x+1,y,cnt+1,a);
        visited[x][y]=0;
        return top+right+left+down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));
        int x=0;int y=0;
        int a=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
                if(grid[i][j]!=-1){
                    a++;
                }
            }
        }
        return helper(grid,visited,x,y,1,a);
    }
};