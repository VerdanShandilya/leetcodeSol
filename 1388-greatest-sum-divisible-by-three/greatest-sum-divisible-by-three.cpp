class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<long long> one;
        vector<long long> two;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0){
                sum+=nums[i];
            }
            else if(nums[i]%3==1){
                one.push_back(nums[i]);
            }
            else{
                two.push_back(nums[i]);
            }
        }
        long long sum1=accumulate(one.begin(), one.end(), 0LL);
        long long sum2=accumulate(two.begin(), two.end(), 0LL);
        long long tsum=sum1+sum2;
        long long diff=LLONG_MAX;
        if(tsum%3==0){
            return sum+tsum;
        }
        if(tsum%3==1){
            if(one.size()>=1){
                diff=one.back();
            }
            if(two.size()>1){
                diff=min(diff,two[two.size()-1]+two[two.size()-2]);
            }
        }
        else{
            if(one.size()>=2){
                diff=one[one.size()-1]+one[one.size()-2];
            }
            if(two.size()>=1){
                diff=min(two.back(),diff);
            }
        }
        return sum+tsum-diff;
    }
};