class Solution {
public:
    bool helper(vector<string> &board, int row, int col) {
        int r=row,c=col;
        while (r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row,c=col;
        while(c>=0){ 
            if(board[r][c] == 'Q')
            return false;
            c--;
        }
        r=row,c=col;
        while(r<board.size() && c>=0){
            if (board[r][c]=='Q')
            return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(helper(board,i,col)){
                board[i][col]='Q';
                solve(col+1,board,ans);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string (n,'.'));
        vector<vector<string>> ans;
        solve(0,board,ans);
        return ans;
    }
};