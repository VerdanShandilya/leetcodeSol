class Solution {
public:
    int ans = 0;

    int helper(string &s, string &t, int i, int j,vector<vector<int>> &dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a;
        if (s[i] == t[j]) {
            a=helper(s, t, i - 1, j - 1,dp)+helper(s,t,i-1,j,dp);
        }
        else{
            a=helper(s, t, i - 1, j,dp);
        }
        return dp[i][j]=a;
        
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp( s.size() , vector<int> (t.size()));  
        for(int i = 0; i < s.size(); i++) { 
            for(int j = 0; j < t.size(); j++) { 
                dp[i][j] =-1; 
            } 
        } 
        return helper(s, t, s.size() - 1, t.size() - 1,dp);
        
    }
};
