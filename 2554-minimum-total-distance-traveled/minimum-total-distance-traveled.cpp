class Solution {
public:
    long long  helper(vector<int>& r, vector<vector<int>>& f,int x,int y,vector<vector<vector<long long>>> &dp){
        if(x>=r.size()){
            return 0;
        }
        if(y>=f.size()){
            return LONG_MAX;
        }
        if (dp[x][y][f[y][1]] != -1){
            return dp[x][y][f[y][1]];
        }
        long long take=1e15;
        if(f[y][1]>0){
            f[y][1]--;
            take=abs(r[x]-f[y][0])+helper(r,f,x+1,y,dp);
            f[y][1]++;
        }
        long  long notake=helper(r,f,x,y+1,dp);
        return dp[x][y][f[y][1]]=min(take,notake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory){
        vector<vector<vector<long long>>> dp(robot.size(), vector<vector<long long>>(factory.size(), vector<long long>(101, -1)));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return helper(robot,factory,0,0,dp);
    }
};
