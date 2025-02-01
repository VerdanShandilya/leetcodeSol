class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<vector<int>> intervals;
        for(int i=0;i<startTime.size();i++){
            intervals.push_back({startTime[i],endTime[i]});
        }
        int n=intervals.size();
        vector<int> gaps;
        gaps.push_back(intervals[0][0]);
        for(int i=1;i<n;i++){
            gaps.push_back(intervals[i][0]-intervals[i-1][1]);
        }
        gaps.push_back(eventTime-intervals[n-1][1]);
        int index=0;
        for(int i=0;i<gaps.size();i++){
            if(gaps[i]>gaps[index]){
                index=i;
            }
        }
        int ans=0;
        int l=0;
        int r=0;
        int cans=0;
        while(r<gaps.size()){
            cans+=gaps[r];
            if(r-l==k){
                ans=max(ans,cans);
                cans-=gaps[l];
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};