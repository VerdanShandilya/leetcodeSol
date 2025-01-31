class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int k=0;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>intervals[i][0]){
                ans++;
                intervals[i][1]=min(intervals[i-1][1],intervals[i][1]);
            }
        }
        return ans;
    }
};