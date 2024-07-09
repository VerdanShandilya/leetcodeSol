class Solution {
public:
    int helper(string &word1, string &word2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        int a;
        if(word1[i]==word2[j]){
            ans=1+helper(word1,word2,i-1,j-1,dp);
        }
        else{
            a=max(helper(word1,word2,i,j-1,dp),helper(word1,word2,i-1,j,dp));
        }
        return dp[i][j]=max(ans,a);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp( word1.size() , vector<int> (word2.size()));  
        for(int i = 0; i < word1.size(); i++) { 
            for(int j = 0; j < word2.size(); j++) { 
                dp[i][j] =-1; 
            } 
        } 
        int a=helper(word1,word2,word1.size()-1,word2.size()-1,dp);
        return (word1.size()-a)+(word2.size()-a);
    }
};