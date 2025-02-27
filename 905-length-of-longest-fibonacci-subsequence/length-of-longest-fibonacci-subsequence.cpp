class Solution {
public:
    int helper(int i,int j,unordered_map<int,int> &m,vector<int> &arr,vector<vector<int>> &dp){
        int count=2;
        int a = arr[i], b = arr[j];
        while(true){
            int sum = a + b;
            if(m.find(sum)!=m.end()){
                a = b;
                b = sum;
                count++;
            }
            else{
                break;
            }
        }
        return dp[i][j]=count;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> m;
        int maxsize = arr[arr.size()-1] + arr[arr.size()-2];
        vector<vector<int>> dp(arr.size()+1,vector<int> (arr.size()+1,-1));
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for( int j=i+1;j<arr.size();j++){
                ans=max(ans,helper(i,j,m,arr,dp));
            }
        }
        return(ans>=3) ? ans : 0;
    }
};