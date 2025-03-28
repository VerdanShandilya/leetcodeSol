class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if(o[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(o.size(), vector<int> (o[0].size(),0));
        dp[0][0]=1;
        for (int i=1;i<o[0].size();i++){
            dp[0][i]=(o[0][i]==1) ? 0:dp[0][i-1];
        }

        for(int i=1;i<o.size();i++){
            dp[i][0]=(o[i][0]==1) ? 0:dp[i-1][0];
        }
        for(int i=1;i<o.size();i++){
            for(int j=1;j<o[0].size();j++){
                if(o[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};