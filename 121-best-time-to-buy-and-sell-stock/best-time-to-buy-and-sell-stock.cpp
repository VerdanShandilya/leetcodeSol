class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(prices[i]);
                continue;
            }
            if(prices[i]<s.top()){
                ans=max(ans,s.top()-prices[i]);
            }
            else{
                s.push(prices[i]);
            }
        }
        return ans;
    }
};