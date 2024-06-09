// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
//         int l=1;
//         int h=0;
//         for(int i=0;i<weights.size();i++){
//             h+=weights[i];
//         }
//         int ans=0;
//         while(l<=h){
//             int mid=(h+l)/2;
//             int count=0;
//             int d=0;
//             for(int i=0;i<weights.size();i++){
//                 if((count+weights[i])<mid){
//                     count+=weights[i];
//                 }
//                 else if((count+weights[i])==mid){
//                     d++;
//                     count=0;
//                 }
//                 else{
//                     count=weights[i];
//                     d++;
//                 }
//             }
//             if(d<=days){
//                 ans=mid;
//                 h=mid-1;
//             }
//             else{
//                 l=mid+1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = -1, totalWeight = 0;
        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight = totalWeight + weight;
        }
        //here weight and total weight work as left and right pointer of bunary search
        while (maxWeight < totalWeight) {
            int midWeight = maxWeight + (totalWeight - maxWeight) / 2;
            int daysNeeded = 1, currWeight = 0;
            for (int weight : weights) {
                if (currWeight + weight > midWeight) {
                    daysNeeded++;
                    currWeight = 0;
                }
                currWeight = currWeight + weight;
            }
            if (daysNeeded > days) {
                maxWeight = midWeight + 1;
            } else {
                totalWeight = midWeight;
            }
        }
        return maxWeight;
    }
};