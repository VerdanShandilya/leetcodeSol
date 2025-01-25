class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        vector<vector<int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        int ans=0;
        while(!q.empty()){
            auto temp=q.front();
            int time=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            q.pop();
            ans=max(ans,time);
            vis[row][col]=true;
            for(int i=0;i<dir.size();i++){
                int nrow=row+dir[i][0];
                int ncol=col+dir[i][1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({time+1,{nrow,ncol}});
                    grid[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};