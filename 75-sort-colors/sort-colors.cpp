// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<int> v;
//         int z=0;
//         int x=1;
//         int c=2;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==z){
//                 v.push_back(z);
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==x){
//                 v.push_back(x);
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==c){
//                 v.push_back(c);
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             nums[i]=v[i];
//         }
//         return;
//     }
// };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};