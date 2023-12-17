class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int z=0;
        s.push(prices[prices.size()-1]);
        for(int i=prices.size()-2;i>=0;i--){
            if(s.empty()){
                continue;
            }
            if(s.top()-prices[i]<0){
                s.pop();
                s.push(prices[i]);
            }
            else{
               z=max(z,(s.top()-prices[i]));
            }
        }
        // int z=0;
        // for(int i=0;i<v.size();i++){
        //     z=max(z,v[i]);
        // }
        return z;
    }
};