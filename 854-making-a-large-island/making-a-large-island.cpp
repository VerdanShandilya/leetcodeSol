class Solution {
public:
    int bfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &vis,int id){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,1}, {0,-1}};

        q.push({i,j});
        vis[i][j]=true;
        int res=1;
        grid[i][j]=id;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(auto i : dir){
                int nrow=row+i.first;
                int ncol=col+i.second;

                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    if(grid[nrow][ncol]==1){
                        res++;
                        grid[nrow][ncol]=id;
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=true;
                    }
                }
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<bool>> vis(n, vector<bool> (n,false));
        unordered_map<int,int> m;
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=bfs(grid,i,j,vis,id);
                    m[id]=size;
                    id++;
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,1}, {0,-1}};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> m1;
                    int nsize=1;
                    for(auto z : dir){
                        int ni=i+z.first;
                        int nj=j+z.second;
                        if (ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]>1) {
                            if (m1.find(grid[ni][nj]) == m1.end()){
                                nsize += m[grid[ni][nj]];
                                m1.insert(grid[ni][nj]);
                            }
                        }
                    }
                    ans=max(ans,nsize);
                }
            }
        }
        return ans == 0 ? n * n : ans;
    }
};