//brute force
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>> s;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 for(int k=j+1;k<nums.size();k++){
//                     for(int l=k+1;l<nums.size();l++){
//                         long long sum=nums[i]+nums[j];
//                         sum+=nums[k]+nums[l];
//                         if(sum==target){
//                             vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
//                             sort(temp.begin(),temp.end());
//                             s.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(s.begin(),s.end());
//         return ans;
//     }
// };

//better
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                set<long> st;
                for(int k=j+1;k<nums.size();k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long fourth=target-sum;
                    if(st.find(fourth)!=st.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};