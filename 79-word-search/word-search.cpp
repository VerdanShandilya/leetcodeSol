class Solution {
public:
    bool helper(vector<vector<char>>& board,string &word,int i,int j,vector<vector<bool>> &vis,int index){
        if(index>=word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index] || vis[i][j]){
            return false;
        }
        vis[i][j]=true;
        bool down=helper(board,word,i+1,j,vis,index+1);
        bool left=helper(board,word,i,j-1,vis,index+1);
        bool right=helper(board,word,i,j+1,vis,index+1);
        bool up=helper(board,word,i-1,j,vis,index+1);
        vis[i][j]=false;
        return down || left || right || up;
    }
    bool exist(vector<vector<char>>& board, string word){
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    if(helper(board,word,i,j,vis,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};