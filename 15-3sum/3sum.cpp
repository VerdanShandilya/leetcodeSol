//optimal
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;     
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};









//Recursive Solution
// class Solution {
// public:
//     void dfs(vector<int>& nums, vector<int>&ans,vector<vector<int>>& fans,int i,int sum){
//         if(sum==0 && ans.size()==3){
//             fans.push_back(ans);
//             return;
//         }
//         if(i>=nums.size()) return;
//         ans.push_back(nums[i]);
//         dfs(nums,ans,fans,i+1,sum+nums[i]);
//         ans.pop_back();
//         while(i+1<nums.size() && nums[i]==nums[i+1]){
//             i=i+1;
//         }
//         dfs(nums,ans,fans,i+1,sum);
        
//     }
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<int> ans;
//         vector<vector<int>> fans;
//         sort(nums.begin(),nums.end());
//         dfs(nums,ans,fans,0,0);
//         return fans;
//     }
// };