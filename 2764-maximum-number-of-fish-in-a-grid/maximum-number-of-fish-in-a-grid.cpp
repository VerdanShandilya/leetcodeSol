class Solution {
public:
    int bfs(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        q.push({i,j});
        vis[i][j]=true;
        int tans=grid[i][j];
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first;
            int col=temp.second;
            q.pop();
            for(auto i : dir){
                int nrow=row+i.first;
                int ncol=col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                    tans+=grid[nrow][ncol];
                }
            }
        }
        return tans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ans=max(ans,bfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};