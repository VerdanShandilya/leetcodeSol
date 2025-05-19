class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> prefix(arr.size(),0);
        prefix[0]=arr[0]-1;
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]+(arr[i]-arr[i-1]-1);
        }
        auto lower=lower_bound(prefix.begin(),prefix.end(),k);
        int index=lower-prefix.begin();
        if(index==0){
            return k;
        }
        int val=arr[index-1];
        return val+(k-prefix[index-1]);
    }
};