class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long r = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans=0;
        long long cans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            cans=0;
            for(int i=0;i<ranks.size();i++){
                cans+=sqrt(mid/ranks[i]); 
            }
            if(cans>=cars){
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