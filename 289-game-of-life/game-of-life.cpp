class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> copy = board;
        vector<pair<int,int>> dir={{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}}; 
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int count = 0;
                for(auto k : dir){
                    int nrow=i+k.first;
                    int ncol=j+k.second;
                    if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && copy[nrow][ncol]==1){
                        count++;
                    }
                }

                if(copy[i][j]==1 && (count<2 || count>3)){
                    board[i][j] = 0; 
                }
                else if(copy[i][j]==0 && count==3){
                    board[i][j] = 1;
                }
            }
        }
    }
};
