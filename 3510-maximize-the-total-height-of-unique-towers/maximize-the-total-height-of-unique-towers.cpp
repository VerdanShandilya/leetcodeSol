class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end());
        long long ans=0;
        int height=maximumHeight[maximumHeight.size()-1];
        for(int i=maximumHeight.size()-1;i>=0;i--){
            height=min(height,maximumHeight[i]);
            if(height<=0){
                return -1;
            }
            ans+=height;
            height--;
        }
        return ans;
    }
};