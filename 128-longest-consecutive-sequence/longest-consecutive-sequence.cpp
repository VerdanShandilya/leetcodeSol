class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans=0;
        int cans=0;
        bool z=false;
        int prev=0;
        for(auto i : s){
            if(z==false || abs(i-prev)==1){
                z=true;
                cans++;
                prev=i;
            }
            else{
                ans=max(ans,cans);
                cans=1;
                prev=i;
            }
        }
        ans=max(ans,cans);
        return ans;
    }
};