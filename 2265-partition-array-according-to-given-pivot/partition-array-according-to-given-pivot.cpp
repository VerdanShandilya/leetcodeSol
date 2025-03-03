class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cpivot=0;
        vector<int> a;
        for(int j=0;j<=nums.size()-1;j++){
            if(nums[j]<pivot){
                a.push_back(nums[j]);
            }
            else if(nums[j]==pivot)
            cpivot++;
        }
        for(int i=0;i<cpivot;i++){
            a.push_back(pivot);
        }
        for(int j=0;j<=nums.size()-1;j++){
            if(nums[j]>pivot){
                a.push_back(nums[j]);
            }
        }
        return a;
    }
};