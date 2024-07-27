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

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>> s;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 set<long> st;
//                 for(int k=j+1;k<nums.size();k++){
//                     long sum=nums[i]+nums[j];
//                     sum+=nums[k];
//                     long fourth=target-sum;
//                     if(st.find(fourth)!=st.end()){
//                         vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
//                         sort(temp.begin(),temp.end());
//                         s.insert(temp);
//                     }
//                     st.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(s.begin(),s.end());
//         return ans;
//     }
// };


//optimal

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};