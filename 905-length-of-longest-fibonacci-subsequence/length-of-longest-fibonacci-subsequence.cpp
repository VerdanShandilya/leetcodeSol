class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> m;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        
        for(int i=0; i<n;i++) {
            m[arr[i]] = i;
        }
        for(int i=0; i<n;i++) { 
            for(int j = 0;j<i;j++) {
                int a = arr[j], b = arr[i];
                int sum = a + b;
                
                if(m.find(sum) != m.end()){
                    int k = m[sum];
                    dp[i][k] = dp[j][i] + 1;
                    ans = max(ans, dp[i][k]);
                }
            }
        }
        
        return (ans >= 3) ? ans : 0;
    }
};
