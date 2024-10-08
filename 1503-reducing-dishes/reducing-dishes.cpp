class Solution {
public:
    int helper(vector<int>& satisfaction,int time,int index,vector<vector<int>> &dp){
        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int pick=satisfaction[index]*time+helper(satisfaction,time+1,index+1,dp);
        int notpick=helper(satisfaction,time,index+1,dp);
        return dp[index][time]=max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>> dp(satisfaction.size(),vector<int> (satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return helper(satisfaction,1,0,dp);
    }
};