class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,INT_MAX-1));
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    q.push({i,j});
                    ans[i][j]=0;
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int, int>> dir = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first;
            int col=temp.second;
            q.pop();
            if(mat[row][col]==0){
                ans[row][col]=0;
            }
            else{
                int z=INT_MAX-1;
                for(auto temp2 : dir){
                    int nrow=row+temp2.first;
                    int ncol=col+temp2.second;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                        z=min(z,ans[nrow][ncol]);
                    }
                }
                ans[row][col]=z+1;
                
            }
            for(auto temp2 : dir){
                int nrow=row+temp2.first;
                int ncol=col+temp2.second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                } 
            }
        }
        return ans;

    }
};