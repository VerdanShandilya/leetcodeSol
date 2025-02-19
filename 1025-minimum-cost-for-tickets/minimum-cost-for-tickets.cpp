class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs,int index,vector<int> &dp){
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int a=costs[0]+helper(days,costs,index+1,dp);
        int z=days[index];
        int c=index;
        while(c<days.size() && z+7>days[c]){
            c++;
        }
        int b=costs[1]+helper(days,costs,c,dp);
        int d=index;
        while(d<days.size() && z+30>days[d]){
            d++;
        }
        int w=costs[2]+helper(days,costs,d,dp);
        return dp[index]=min({a,b,w});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return helper(days,costs,0,dp);
    }
};