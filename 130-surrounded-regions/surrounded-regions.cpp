class Solution {
public:
    void helper(vector<vector<char>>& board,vector<vector<bool>> &vis,queue<pair<int,int>> &q){
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            for(auto i : dir){
                int nrow = i.first+row;
                int ncol = i.second+col;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=true;
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1]=true;
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=true;
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                q.push({n-1,j});
                vis[n-1][j]=true;
            }
        }
        helper(board,vis,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
