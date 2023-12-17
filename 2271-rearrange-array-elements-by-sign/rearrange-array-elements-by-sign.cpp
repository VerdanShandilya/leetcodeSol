class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> vp;
        vector<int> vn;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                vp.push_back(nums[i]);
            }
            else{
                vn.push_back(nums[i]);
            }
        }int z=0;
        while(z<vp.size() && z<vn.size()){
            ans.push_back(vp[z]);
            ans.push_back(vn[z]);
            z++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         int positiveElementIndex = 0, negativeElementIndex = 1;

//         for(auto num : nums){
//             if(num > 0){
//                 ans[positiveElementIndex] = num;
//                 positiveElementIndex += 2;
//             }
//             else if(num < 0){
//                 ans[negativeElementIndex] = num;
//                 negativeElementIndex += 2;
//             }
//         }
//         return ans;
//     }
// };
