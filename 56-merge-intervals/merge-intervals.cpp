class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int a=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[a][1]>=intervals[i][0]){
                intervals[a][1]=max(intervals[a][1],intervals[i][1]);
            }
            else{
                a++;
                intervals[a]=intervals[i];
            }
        }
        intervals.resize(a+1);
        return intervals;
    }
};