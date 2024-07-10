class Solution {
public:
    int helper(string &s,string &b,int i,int j,vector<vector<int>> &dp){
        if(i>s.size()-1 || j>b.size()-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        if(s[i]==b[j]){
            a=1+helper(s,b,i+1,j+1,dp);
        }
        else{
            a=max(helper(s,b,i+1,j,dp),helper(s,b,i,j+1,dp));
        }
        return dp[i][j]=a;
    }
    int minInsertions(string s) {
        string b(s.rbegin(),s.rend());
        vector<vector<int>> dp( s.size() , vector<int> (b.size()));  
        for(int i = 0; i < s.size(); i++) { 
            for(int j = 0; j < b.size(); j++) { 
                dp[i][j] =-1; 
            } 
        } 
        return s.size()-helper(s,b,0,0,dp);
    }
};