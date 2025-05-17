class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            int tdays=1;
            for(int i=0;i<weights.size();i++){
                sum+=weights[i];
                if(sum>mid){
                    tdays++;
                    sum=weights[i];
                }
            }
            if(tdays<=days){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};