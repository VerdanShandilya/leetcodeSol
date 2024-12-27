class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int, int>> dir = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        int tm=0;
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first.first;
            int col=temp.first.second;
            int time=temp.second;
            tm=max(tm,time);
            q.pop();
            for(auto temp2 : dir){
                int nrow=row+temp2.first;
                int ncol=col+temp2.second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    grid[nrow][ncol]=2;
                    vis[nrow][ncol]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};