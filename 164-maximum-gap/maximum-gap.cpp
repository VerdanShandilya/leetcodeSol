class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int j=0;
        for(auto i : m){
            int count=i.second;
            while(count--){
                nums[j]=i.first;
                j++;
            }
        }
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans=max(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};