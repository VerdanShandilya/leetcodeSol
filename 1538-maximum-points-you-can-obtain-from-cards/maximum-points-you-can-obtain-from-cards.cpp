class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int sum=0;
        for(auto i: card){
            sum+=i;
        }
        if(card.size()==k)
        return sum;
        int ans=0;
        int l=0;
        int r=0;
        int csum=0;
        while(r<card.size()){
            csum+=card[r];
            if(r-l+1==card.size()-k){
                ans=max(ans,sum-csum);
                csum=csum-card[l];
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};