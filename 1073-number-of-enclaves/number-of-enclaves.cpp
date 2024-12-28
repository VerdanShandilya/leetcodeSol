class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0){
            return;
        }
        if(grid[i][j]==1)
        vis[i][j]=true;
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j-1,vis);
        dfs(grid,i,j+1,vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int> (m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(grid,i,0,vis);
            }
            if(grid[i][m-1] && !vis[i][m-1]){
                dfs(grid,i,m-1,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(grid,0,j,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(grid,n-1,j,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
};