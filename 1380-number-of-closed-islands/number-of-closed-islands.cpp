class Solution {
public:
    int helper(vector<vector<int>>& grid,vector<vector<bool>> &vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{0,1}, {0,-1}, {-1,0}, {1,0}};
        bool flag=false;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            if(row==0 || col==0 || row==n-1 || col==m-1){
                flag=true;
            }
            for(auto i : dir){
                int nrow=i.first+row;
                int ncol=i.second+col;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
        if(flag)
        return 0;
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n ,vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    
                    ans+=helper(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};