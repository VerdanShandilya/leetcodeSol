class Solution {
public:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i>=s1.size()){
            int res=0;
            for(int x=j;x<s2.size();x++){
                res+=s2[x];
            }
            return res;
        }
        if(j>=s2.size()){
            int res=0;
            for(int x=i;x<s1.size();x++){
                res+=s1[x];
            }
            return res;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int sum=INT_MAX;
        if(s1[i]==s2[j]){
            sum=helper(s1,s2,i+1,j+1,dp);
        }
        int a=int(s1[i])+helper(s1,s2,i+1,j,dp);
        int b=int(s2[j])+helper(s1,s2,i,j+1,dp);
        return dp[i][j]=min({a,b,sum});
    }
    int minimumDeleteSum(string s1, string s2){
        vector<vector<int>> dp(s1.size(), vector<int> (s2.size(),-1));
        return helper(s1,s2,0,0,dp);
    }
};