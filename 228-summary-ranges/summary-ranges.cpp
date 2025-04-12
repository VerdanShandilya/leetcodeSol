class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string s="";
        int i=0;
        while(i<nums.size()){
            int start=nums[i];
            while(i+1<nums.size()  && nums[i]==nums[i+1]-1){
                i++;
            }
            int e=nums[i];
            if(start==e){
                ans.push_back(to_string(start));
            }
            else{
                ans.push_back(to_string(start) + "->" + to_string(e));
            }
            i++;
        }
        return ans;
    }
};