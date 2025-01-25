class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int co=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vector<vector<int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        vis[sr][sc]=true;
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first;
            int col=temp.second;
            q.pop();
            vis[row][col]=true;
            for(auto j : dir){
                int nrow=row+j[0];
                int ncol=col+j[1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==co){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};