class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>> &vis,int i,int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j] || board[i][j]=='X'){
            return;
        }
        if(board[i][j]=='O'){
            vis[i][j]=true;
        }
        dfs(board,vis,i+1,j);
        dfs(board,vis,i-1,j);
        dfs(board,vis,i,j+1);
        dfs(board,vis,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(board,vis,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(board,vis,0,i);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(board,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};