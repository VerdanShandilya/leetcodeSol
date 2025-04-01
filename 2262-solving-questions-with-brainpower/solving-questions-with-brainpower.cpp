class Solution {
public:
    long long helper(vector<vector<int>>& questions,int index,vector<long long> &dp){
        if(index>=questions.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        long long pick=questions[index][0]+helper(questions,index+questions[index][1]+1,dp);
        long long notpick=helper(questions,index+1,dp);
        return dp[index]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions){
        vector<long long> dp(questions.size(),-1);
        return helper(questions,0,dp);
    }
};