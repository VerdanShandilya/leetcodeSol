class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long r=1LL*(*max_element(time.begin(),time.end()))*totalTrips;
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long trips=0;
            for(int i=0;i<time.size();i++){
                trips+=mid/time[i];
            }
            if(trips>=totalTrips){
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