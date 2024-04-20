class Solution {
public:
    void eraser(vector<vector<char>>& board,int i,int j){
        int n=board.size();
        int m= board[0].size();
        if(i<0 || j<0 || i==n || j==m || board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        eraser(board,i+1,j);
        eraser(board,i-1,j);
        eraser(board,i,j+1);
        eraser(board,i,j-1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='X'){
                    count++;
                    eraser(board,i,j);
                }
            }
        }
        return count;
    }
};