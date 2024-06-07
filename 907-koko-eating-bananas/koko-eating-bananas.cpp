class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int high=INT_MIN;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=0;
        while(l<=high){
            int mid=(l+high)/2;
            long long time=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]>mid){
                    int z= ceil(piles[i] / (double)mid);
                    time+=z;
                } 
                else{
                    time++;
                }  
            }
            if(time>h){
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