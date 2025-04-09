class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix[0].size()-1;
        int c=0;
        while(c>=0 && c<matrix.size() && r>=0 && r<matrix[0].size()){
            if(matrix[c][r]>target){
                r--;
            }
            else if(matrix[c][r]==target){
                return true;
            }
            else{
                c++;
            }
        }
        return false;
    }
};