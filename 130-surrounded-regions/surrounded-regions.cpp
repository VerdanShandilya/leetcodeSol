class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' &&(i==0 || j==0 ||i==n-1 || j==m-1)){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            vis[row][col]=true;
            for(auto [x,y] : dir){
                int nrow=row+x;
                int ncol=col+y;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};