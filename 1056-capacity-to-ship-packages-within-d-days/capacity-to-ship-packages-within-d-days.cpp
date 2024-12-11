class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        int l=-1;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
            l=max(weights[i],l);
        }
        int ans=0;
        while(l<=high){
            int mid=l+(high-l)/2;
            int tdays=1;
            int cap=0;
            for(int i=0;i<weights.size();i++){
                if(cap+weights[i]<=mid){
                    cap+=weights[i];
                }
                else{
                    tdays++;
                    cap=weights[i];
                }
            }
            if(tdays>days){
                l=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};