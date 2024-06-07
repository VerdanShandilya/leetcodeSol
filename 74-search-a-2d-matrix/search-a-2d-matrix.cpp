class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[i].size()-1;
        bool z=false;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                z=true;
                break;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return z;
    }
};