// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         long count=0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i+1]-nums[i]>0){
//                 continue;
//             }
//             else{
//                 long c=abs(nums[i+1]-nums[i]);
//                 c+=1;
//                 nums[i+1]=nums[i+1]+c;
//                 count+=c;
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
  sort(begin(A), end(A));
         int res = 0;
  for (auto i = 1; i < A.size(); ++i) {
      if(A[i]>A[i-1]){
          continue;
      }else{
          res += A[i-1]-A[i]+1;
          A[i] = A[i-1]+1;
      }
  }
  return res;
}
};