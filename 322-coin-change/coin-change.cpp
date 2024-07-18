class Solution {
public:
    int helper(vector<int>& coins, int amount, int i,vector<vector<int>> &memo) {
        if (amount == 0) {
            return 0;
        }
        if (i > coins.size() - 1|| amount<0) {
            return INT_MAX-1;
        }
        if(memo[amount][i]!= -1) return memo[amount][i];
        int a=1+helper(coins, amount - coins[i], i,memo);
        int b=helper(coins, amount, i + 1,memo);
        return memo[amount][i] =min(a,b);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo;
        memo.resize(amount + 1,vector<int>(coins.size(), -1));
        int a=helper(coins, amount, 0,memo);
        if (a<INT_MAX-1) {
            return a;
        }
        return -1;
    }
};
