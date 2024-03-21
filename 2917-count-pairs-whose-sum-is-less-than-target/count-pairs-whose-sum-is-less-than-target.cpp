// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target) {
//         int i=0;int z=0;
//         int j=1;
//         int count=0;
//         while(z<nums.size() && i<j){
//             if(nums[i]+nums[j]<target){
//                 count++;
//             }
//             if(j==nums.size()-1){
//                 i++;
//                 j=i+1;
//                 z=j;
//                 continue;
//             }
//             j++;
//             z++;
//         }
//         return count;
//     }
// };
class Solution {
public:
  int countPairs(vector<int>& nums , int target){ // function to count the pairs whose sum is less than target
      sort(nums.begin() , nums.end()); // sort the vector nums
      int count = 0; // variable to store the count
      int left = 0; // variable to store the left
      int right = nums.size()-1; // variable to store the right
      while(left < right){ // loop until left is less than right
          if(nums[left] + nums[right] < target){ // if nums[left] + nums[right] is less than target
              count += right-left; // update the count
              left++; // increment the left
          }
          else{ // else
              right--; // decrement the right
          }
      }
      return count; // return the count
  }
};