class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> temp(matrix.size(),vector<bool> (matrix[0].size(),false));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                temp[i][j]=true;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(temp[i][j]==true){
                    for(int k=0;k<matrix.size();k++){
                        matrix[k][j]=0;
                    }
                    for(int k=0;k<matrix[0].size();k++){
                        matrix[i][k]=0;
                    }
                }
            }
        }    
    }
};