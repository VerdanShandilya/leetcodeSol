class Solution {
public:
    // void bfs(vector<vector<char>>& board,vector<vector<bool>> &vis,int i,int j){
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     vis[i][j]=true;
    //     vector<pair<int,int>> dir={{-1, 0},{1, 0},{0, -1},{0, 1}};
    //     while(!q.empty()){
    //         auto temp=q.front();
    //         int row=temp.first;
    //         int col=temp.second;
    //         q.pop();
    //         vis[row][col]=true;
    //         for(auto temp2 : dir){
    //             int nrow=row+temp2.first;
    //             int ncol=col+temp2.second;
    //             if(nrow>=0 && ncol>=0 && nrow<=board.size()-1 && ncol<=board[0].size()-1 && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
    //                 q.push({nrow,ncol});
    //             }
    //         }
    //     }
    // }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) &&board[i][j]=='O' ){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int,int>> dir={{-1, 0},{1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            auto temp=q.front();
            int row=temp.first;
            int col=temp.second;
            q.pop();
            vis[row][col]=true;
            for(auto temp2 : dir){
                int nrow=row+temp2.first;
                int ncol=col+temp2.second;
                if(nrow>=0 && ncol>=0 && nrow<=board.size()-1 && ncol<=board[0].size()-1 && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                }
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