class Solution {
public:
    int ans=INT_MAX;
    int helper(vector<vector<int>>& triangle,int row,int column,vector<vector<int>> &dp){
        if(row>triangle.size()-1 || column>triangle[row].size()-1){
            return 0;
        }
        if(dp[row][column]!=INT_MAX-1){
            return dp[row][column];
        }
        int a=triangle[row][column]+helper(triangle,row+1,column,dp);
        int b=triangle[row][column]+helper(triangle,row+1,column+1,dp);
        return dp[row][column]=min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp( triangle.size()+1 , vector<int> (triangle.size()+1));  
        for(int i = 0; i < triangle.size()+1; i++){ 
            for(int j = 0; j < triangle.size()+1; j++) { 
                dp[i][j] =INT_MAX-1; 
            } 
        } 
        return helper(triangle,0,0,dp);
    }
};