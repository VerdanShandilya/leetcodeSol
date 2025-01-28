class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || !grid[i][j]){
            return 0;
        }
        vis[i][j]=true;
        int up=dfs(grid,i-1,j,vis);
        int down=dfs(grid,i+1,j,vis);
        int left=dfs(grid,i,j-1,vis);
        int right=dfs(grid,i,j+1,vis);
        return grid[i][j]+up+down+left+right;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    vector<vector<bool>> vis(n, vector<bool> (m,false));
                    ans=max(dfs(grid,i,j,vis),ans);
                }
            }
        }
        return ans;
    }
};