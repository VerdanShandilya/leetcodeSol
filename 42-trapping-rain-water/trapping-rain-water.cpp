class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int leftmax=0;
        for(int i=0;i<height.size();i++){
            left[i]=leftmax;
            leftmax=max(leftmax,height[i]);
        }
        int rightmax=0;
        int ans=0;
        for(int i=height.size()-1;i>=0;i--){
            right[i]=rightmax;
            rightmax=max(rightmax,height[i]);
            ans=ans+max(0,(min(left[i],right[i])-height[i]));
        }
        return ans;
    }
};