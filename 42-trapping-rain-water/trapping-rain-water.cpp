class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int leftmax=0;
        for(int i=0;i<n;i++){
            left[i]=leftmax;
            leftmax=max(leftmax,height[i]);
        }
        int ans=0;
        int rightmax=0;
        for(int i=n-1;i>=0;i--){
            right[i]=rightmax;
            rightmax=max(rightmax,height[i]);
            ans+=max(0,min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};