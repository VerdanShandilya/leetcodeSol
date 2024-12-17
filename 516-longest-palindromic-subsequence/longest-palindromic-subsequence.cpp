class Solution {
public:
    int helper(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a,b;
        a=b=0;
        if(s[i-1]==p[j-1]){
            a=1+helper(s,p,i-1,j-1,dp);
        }
        else{
            b=max(helper(s,p,i-1,j,dp),helper(s,p,i,j-1,dp));
        }
        return dp[i][j]=max(a,b);
    }
    int longestPalindromeSubseq(string s) {
        string p="";
        for(int i=s.size()-1;i>=0;i--){
            p+=s[i];
        }
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        return helper(s,p,s.size(),p.size(),dp);
    }
};