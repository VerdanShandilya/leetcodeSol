class Solution {
public:
    int helper(vector<vector<int>>& grid,vector<vector<bool>> &vis,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vis[i][j]=true;
        q.push({i,j});
        int ans = 1;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            for(auto i : dir){
                int nrow = row+i.first;
                int ncol = col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    ans++;
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans = max(ans,helper(grid,vis,i,j));
                }
            }
        }
        return ans;
    }
};
