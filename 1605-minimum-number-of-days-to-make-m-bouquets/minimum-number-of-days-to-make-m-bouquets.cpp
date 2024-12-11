class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int bc=0;
            int kc=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]>mid){
                    kc=0;
                }
                else{
                    kc++;
                }
                if(kc==k){
                    bc++;
                    kc=0;
                }
            }
            if(bc<m){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};