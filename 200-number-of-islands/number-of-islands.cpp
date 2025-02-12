class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            for(auto i : dir){
                int nrow=row+i.first;
                int ncol=col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};