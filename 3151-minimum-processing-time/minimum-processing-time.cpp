class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end(),greater<int>());
        sort(tasks.begin(),tasks.end());
        if(processorTime.size()==1){
            return processorTime[0]+tasks[3];
        }
        int j=4;
        int ans=processorTime[0]+tasks[3];
        for(int i=1;i<processorTime.size();i++){
            ans=max(ans,processorTime[i]+tasks[j+3]);
            j=j+4;
        }
        return ans;
    }
};