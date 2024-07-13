class Solution {
public:
    int count=0;
    int helper(int m, int n,int i,int j,vector<vector<int>> &dp){
        if(i==m && j==n){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>m || j>n){
            return 0;
        }
        int a=helper(m,n,i+1,j,dp);
        int b=helper(m,n,i,j+1,dp);
        return dp[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m+1 , vector<int> (n+1));  
        for(int i = 0; i <m+1; i++) { 
            for(int j = 0; j <n+1; j++) { 
                dp[i][j] =-1; 
            } 
        } 
        return helper(m-1,n-1,0,0,dp);
    }
};