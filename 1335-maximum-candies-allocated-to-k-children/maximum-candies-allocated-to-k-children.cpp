class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left=1;
        long long right=*max_element(candies.begin(), candies.end());
        int res=0;

        while(left<=right){
            long long mid=left+(right-left)/2;
            long long count=0;
            for (int pile : candies) {
                count+=pile/mid;
            }
            if(count>=k){
                res=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return res;
    }
};