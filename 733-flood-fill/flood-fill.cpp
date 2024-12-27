class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int scolor=grid[sr][sc];
        grid[sr][sc]=color;
        vis[sr][sc]=true;
        vector<pair<int, int>> dir = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first;
            int col=temp.second;
            q.pop();
            for(auto temp2 : dir){
                int nrow=row+temp2.first;
                int ncol=col+temp2.second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==scolor && !vis[nrow][ncol]){
                    grid[nrow][ncol]=color;
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        return grid;
    }
};