class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0;
        // bool compare(const vector<int>& a, const vector<int>& b){
        //     return a[1] > b[1];
        // }
        sort(boxTypes.begin(), boxTypes.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        int j=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][j]<truckSize){
                ans+=boxTypes[i][j]*boxTypes[i][j+1];
                truckSize-=boxTypes[i][j];
            }
            else {
                ans+=boxTypes[i][j+1]*truckSize;
                break;
            }
        }
        return ans;
    }
};