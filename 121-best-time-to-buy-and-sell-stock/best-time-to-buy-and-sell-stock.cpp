class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        stack<int> s;
        if(prices.size()==1){
            return ans;
        }
        s.push(prices[prices.size()-1]);
        for(int i=prices.size()-2;i>=0;i--){
            if(s.top()<prices[i]){
                s.pop();
                s.push(prices[i]);
            }
            else if(s.top()>prices[i]){
                ans=max(ans,s.top()-prices[i]);
            }
        }
        return ans;
    }
};