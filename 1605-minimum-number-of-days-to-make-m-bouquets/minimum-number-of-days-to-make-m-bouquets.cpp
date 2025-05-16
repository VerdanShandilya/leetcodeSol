class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int l=*min_element(b.begin(),b.end());
        int r=*max_element(b.begin(),b.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int flowers=0;
            int count=0;
            for(int i=0;i<b.size();i++){
                if(b[i]<=mid){
                    count++;
                }
                else{
                    count=0;
                }
                if(count==k){
                    count=0;
                    flowers++;
                }
            }
            if(flowers>=m){
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