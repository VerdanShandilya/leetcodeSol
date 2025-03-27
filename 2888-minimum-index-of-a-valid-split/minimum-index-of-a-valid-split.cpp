class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom=0;
        int domn=0;
        unordered_map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        for(auto i : m){
            if(i.second>domn){
                dom=i.first;
                domn=i.second;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==dom){
                count++;
            }
            int left=i+1;
            int right=nums.size()-left;
            int rightc=domn-count;
            if(count>left/2 && rightc>right/2){
                return i;
            }  
        }
        return -1;
    }
};