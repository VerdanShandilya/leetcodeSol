class Solution {
public:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i>=s1.size() || j>=s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        if(s1[i]==s2[j]){
            a=1+helper(s1,s2,i+1,j+1,dp);
        }
        int b=helper(s1,s2,i,j+1,dp);
        int c=helper(s1,s2,i+1,j,dp);
        return dp[i][j]=max({a,b,c});
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size(),-1));
        return helper(text1,text2,0,0,dp);
    }
};